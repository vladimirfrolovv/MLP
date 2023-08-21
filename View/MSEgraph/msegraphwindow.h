#ifndef CPP7_MLP_2_SRC_VIEW_MSEGRAPHWINDOW_MSEGRAPHWINDOW_H_
#define CPP7_MLP_2_SRC_VIEW_MSEGRAPHWINDOW_MSEGRAPHWINDOW_H_

#include <QWidget>

#include "../../Controller/controller.h"

namespace Ui {
class msegraphwindow;
}

namespace s21 {
/**
 * @brief Класс - виджет. Нужен для отрисовки графика MSE нейросети.
 */
class Msegraphwindow : public QWidget {
  Q_OBJECT

 public:
  explicit Msegraphwindow(QWidget* parent = nullptr);
  ~Msegraphwindow();
  void PrintGraph();

 private:
  Ui::msegraphwindow* ui;
  s21::Controller* controller;
};

}  // namespace s21

#endif  // CPP7_MLP_2_SRC_VIEW_MSEGRAPHWINDOW_MSEGRAPHWINDOW_H_
