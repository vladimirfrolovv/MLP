#include "worker.h"

// Класс, представляющий длительную задачу, которую мы хотим выполнить в
// отдельном потоке

s21::Worker::Worker(Statuswindow *status, s21::Controller *controller,
                    size_t epoch, size_t hidden_layers, bool crossIsCheck,
                    size_t kgroup, std::string path)
    : status_(status),
      controller_(controller),
      epoch_(epoch),
      hidden_layers_(hidden_layers),
      crossIsCheck_(crossIsCheck),
      kgroup_(kgroup),
      path_(path) {}

void s21::Worker::doWork() {
  controller_->InitNetwork(create_config(), controller_->GetTypeNetwork());
  QThread::sleep(1);
  controller_->GetTypeNetwork()
      ? emit updateStatus("Инициализирована ГРАФОВАЯ нейросеть с " +
                          QString::number(hidden_layers_) + " скрытыми слоями")
      : emit updateStatus("Инициализирована МАТРИЧНАЯ нейросеть с " +
                          QString::number(hidden_layers_) + " скрытыми слоями");
  crossIsCheck_
      ? emit updateStatus("Кросс-валидация включена, количество групп k:" +
                          QString::number(kgroup_))
      : emit updateStatus("Кросс-валидация НЕ включена");
  QThread::sleep(1);
  emit updateStatus("Количество эпох обучения нейросети: " +
                    QString::number(epoch_));
  QThread::sleep(1);
  emit updateStatus("Начался процесс обучения...");
  time_t all_trainig = time(0);
  for (size_t i = 0; i < epoch_; i++) {
    time_t epoch_time = time(0);
    emit updateStatus("эпоха №: " + QString::number(i + 1));
    if (crossIsCheck_) {
      controller_->TrainWithCrossValidation(path_, kgroup_);
    } else {
      controller_->Train(path_);
    }
    emit updateStatus("Значение MSE для эпохи " +
                      QString::number(controller_->GetMse()));
    emit updateStatus("Время обучения для эпохи: " +
                      QString::number(time(0) - epoch_time) + " sec");
    controller_->forMSEgraph.push_back(controller_->GetMse());
  }
  emit updateStatus("Общее время обучения: " +
                    QString::number(time(0) - all_trainig) + " sec");
  emit updateStatus("Обучение завершено");
  // Отправляем сигнал, что задача выполнена
  emit workDone();
}

std::vector<size_t> s21::Worker::create_config() {
  std::vector<size_t> config{};
  config.push_back(784);
  for (size_t i = 0; i < hidden_layers_; i++) {
    config.push_back(64);
  }
  config.push_back(26);
  return config;
}
