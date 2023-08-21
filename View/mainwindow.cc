#include "mainwindow.h"

#include <QValidator>

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  setWindowTitle("Многослойный перцептрон v1.0");
  status_ = new s21::Statuswindow;
  controller_ = s21::Controller::GetInstance();
  msegraph_ = new s21::Msegraphwindow;
  timeElapsed_ = QTime(0, 0, 0);
}

MainWindow::~MainWindow() {
  delete ui;
  delete controller_;
  delete msegraph_;
  delete status_;
}

void MainWindow::startTrainNetworkInThread(std::string path) {
  timerTrainNetworkStart();

  QThread *thread = new QThread;
  s21::Worker *worker = new s21::Worker(
      status_, controller_, ui->epochs_count->value(),
      ui->hidden_layers_count->value(), ui->cross_validation->isChecked(),
      ui->number_of_groups_k->value(), path);

  // Подключаем сигнал о завершении работы задачи к удалению потока и worker'а
  connect(worker, &s21::Worker::workDone, thread, &QThread::quit);
  connect(worker, &s21::Worker::workDone, worker, &s21::Worker::deleteLater);
  connect(thread, &QThread::finished, thread, &QThread::deleteLater);
  connect(thread, &QThread::finished, this, &MainWindow::afterFinishedThread);
  connect(thread, &QThread::finished, this, &MainWindow::timerTrainNetworkStop);

  connect(worker, &s21::Worker::updateStatus, this,
          &MainWindow::updateStatusMessage);
  // Перемещаем worker в поток
  worker->moveToThread(thread);

  // Запускаем длительную задачу в потоке
  connect(thread, &QThread::started, worker, &s21::Worker::doWork);
  thread->start();
}

void MainWindow::on_train_network_clicked() {
  training_dataset_path_ =
      QFileDialog::getOpenFileName(this, tr("Open File"), ".",
                                   tr("train files (*.csv)"))
          .toStdString();
  if (!training_dataset_path_.empty()) {
    ui->train_network->setEnabled(false);
    status_->show();
    startTrainNetworkInThread(training_dataset_path_);
  }
}

void MainWindow::timerTrainNetworkStart() {
  timer_ = new QTimer(this);
  connect(timer_, &QTimer::timeout, this, &MainWindow::updateTime);
  timer_->start(1000);
}

void MainWindow::timerTrainNetworkStop() { timer_->stop(); }

void MainWindow::updateTime() {
  timeElapsed_ = timeElapsed_.addSecs(1);
  status_->setTime(timeElapsed_);
}

void MainWindow::afterFinishedThread() {
  ChangeAvailabilityOfButtonsAfterTraining();
  status_->enable(true);
  controller_->SetIsTrained(true);
}

void MainWindow::ChangeAvailabilityOfButtonsAfterTraining() {
  ui->define_letter->setEnabled(true);
  ui->start_test->setEnabled(true);
  ui->open_mse_graph->setEnabled(true);
  ui->define_letter_from_bmp->setEnabled(true);
  ui->restart_training->setEnabled(true);
  ui->graphicsView->setEnabled(true);
  ui->save_weights->setEnabled(true);
  ui->load_weights->setEnabled(false);
  ui->graph_model->setEnabled(false);
  ui->matrix_model->setEnabled(false);
  ui->epochs_count->setEnabled(false);
  ui->hidden_layers_count->setEnabled(false);
  ui->cross_validation->setEnabled(false);
  ui->number_of_groups_k->setEnabled(false);
  ui->train_network->setEnabled(false);
  ui->start_test->setFocus();
}

void MainWindow::ChangeAvailabilityOfButtonsAfterReset() {
  ui->define_letter->setEnabled(false);
  ui->start_test->setEnabled(false);
  ui->open_mse_graph->setEnabled(false);
  ui->define_letter_from_bmp->setEnabled(false);
  ui->restart_training->setEnabled(false);
  ui->graphicsView->setEnabled(false);
  ui->save_weights->setEnabled(false);
  ui->load_weights->setEnabled(true);
  ui->graph_model->setEnabled(true);
  ui->matrix_model->setEnabled(true);
  ui->epochs_count->setEnabled(true);
  ui->hidden_layers_count->setEnabled(true);
  ui->cross_validation->setEnabled(true);
  ui->number_of_groups_k->setEnabled(true);
  ui->train_network->setEnabled(true);
  ui->start_test->setFocus();
  delete msegraph_;
  msegraph_ = new s21::Msegraphwindow;
  delete status_;
  status_ = new s21::Statuswindow;
}

void MainWindow::on_start_test_clicked() {
  testing_dataset_path_ =
      QFileDialog::getOpenFileName(this, tr("Open File"), ".",
                                   tr("test files (*.csv)"))
          .toStdString();
  time_t now = time(0);
  controller_->Test(testing_dataset_path_, ui->test_file_part->value());
  ui->time_spent->setText(QString::number(time(0) - now) + " sec");
  UpdateTestingResultsAfterTesting();
}

void MainWindow::UpdateTestingResultsAfterTesting() {
  ui->average_accuracy->setText(
      QString::number(controller_->GetAverageAccuracy(), 'f', 2));
  ui->precision_for_letter->setText(
      QString::number(controller_->GetPrecisions(), 'f', 2));
  ui->recall_for_letter->setText(
      QString::number(controller_->GetRecalls(), 'f', 2));
  ui->f_measure_for_letter->setText(
      QString::number(controller_->GetFMeasures(), 'f', 2));
}

void MainWindow::on_define_letter_clicked() {
  ui->answer->setText((QChar)controller_->GetAnswer());
}

void MainWindow::on_save_weights_clicked() {
  std::string filepath = QFileDialog::getSaveFileName(
                             this, "Save as...", "weight.txt", "Txt (*.txt)")
                             .toStdString();
  controller_->SaveWeights(filepath);
  if (!filepath.empty()) {
    ui->save_weights->setEnabled(false);
  }
}

void MainWindow::on_load_weights_clicked() {
  std::string filepath = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                      tr("Text Files (*.txt)"))
                             .toStdString();
  if (!controller_->LoadWeights(filepath, controller_->GetTypeNetwork())) {
    QMessageBox::about(this, "Ошибка", "Не удалось загрузить веса");
  } else {
    ChangeAvailabilityOfButtonsAfterTraining();
    ui->open_mse_graph->setEnabled(false);
    ui->showStatus->setEnabled(false);
  }
}

void MainWindow::on_define_letter_from_bmp_clicked() {
  QImage img = QImage(QFileDialog::getOpenFileName(
      this, tr("Open File"), "/path/to/file/", tr("Object Files (*.bmp)")));
  if (img.size().width() != img.size().height() || img.size().width() > 512 ||
      img.size().height() > 512 || img.size().width() < 28 ||
      img.size().height() < 28) {
    QMessageBox::about(this, "Ошибка",
                       "Выберите квадратное изображение .bmp не меньше "
                       "28x28 и не больше 512x512");
  } else {
    img = img.scaled(28, 28);
    img = img.transformed(QTransform().rotate(-90));

    std::vector<float> Pixels;
    Pixels.push_back(-1);
    for (int i = img.size().width() - 1; i >= 0; i--) {
      for (int j = 0; j < img.size().height(); j++) {
        Pixels.push_back(img.pixelColor(j, i).black() / 255.f);
      }
    }
    controller_->TestOneLetter(Pixels);
    ui->answer->setText((QChar)controller_->GetAnswer());
  }
}

void MainWindow::on_open_mse_graph_clicked() {
  if (ui->epochs_count->value() > 1) {
    msegraph_->setWindowTitle("Graph MSE/Epochs");
    msegraph_->show();
    msegraph_->PrintGraph();
  } else {
    QMessageBox::about(
        this, "Ошибка",
        "для построения графика необходимо более одной эпохи обучения");
  }
}

void MainWindow::updateStatusMessage(QString message) {
  status_->append(message);
}

void MainWindow::on_restart_training_clicked() {
  controller_->ResetTraining();
  ChangeAvailabilityOfButtonsAfterReset();
  timeElapsed_ = QTime(0, 0, 0);
}

void MainWindow::on_showStatus_clicked() { status_->show(); }

void MainWindow::on_graph_model_clicked() {
  controller_->SetTypeNetwork(GRAPH);
}
void MainWindow::on_matrix_model_clicked() {
  controller_->SetTypeNetwork(MATRIX);
}
