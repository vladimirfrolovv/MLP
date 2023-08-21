#ifndef CPP7_MLP_2_SRC_VIEW_MAINWINDOW_MAINWINDOW_H_
#define CPP7_MLP_2_SRC_VIEW_MAINWINDOW_MAINWINDOW_H_

#include <QtOpenGLWidgets/qopenglwidget.h>

#include <QFileDialog>
#include <QMainWindow>
#include <QTime>
#include <QVector>
#include <QWidget>
#include <QtWidgets>
#include <iostream>

#include "../Controller/controller.h"
#include "Form/form.h"
#include "MSEgraph/msegraphwindow.h"
#include "Statuswindow/statuswindow.h"
#include "Worker/worker.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  explicit MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private slots:
  void on_train_network_clicked();
  void ChangeAvailabilityOfButtonsAfterTraining();
  void ChangeAvailabilityOfButtonsAfterReset();
  void UpdateTestingResultsAfterTesting();

  void on_start_test_clicked();
  void on_define_letter_clicked();

  void on_save_weights_clicked();
  void on_load_weights_clicked();

  void on_define_letter_from_bmp_clicked();

  void on_open_mse_graph_clicked();
  void startTrainNetworkInThread(std::string path);
  void updateStatusMessage(QString message);

  void afterFinishedThread();
  void on_restart_training_clicked();
  void updateTime();

  void timerTrainNetworkStart();
  void timerTrainNetworkStop();

  void on_showStatus_clicked();

  void on_graph_model_clicked();

  void on_matrix_model_clicked();

 private:
  Ui::MainWindow *ui;
  s21::Controller *controller_;
  s21::Msegraphwindow *msegraph_;
  s21::Statuswindow *status_;

  QTime timeElapsed_;
  QTimer *timer_;

  std::string training_dataset_path_{};
  std::string testing_dataset_path_{};
};

#endif  // CPP7_MLP_2_SRC_VIEW_MAINWINDOW_MAINWINDOW_H
