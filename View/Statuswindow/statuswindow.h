#ifndef CPP7_MLP_2_SRC_VIEW_STATUSWINDOW_STATUSWINDOW_H_
#define CPP7_MLP_2_SRC_VIEW_STATUSWINDOW_STATUSWINDOW_H_

#include <QTime>
#include <QWidget>

namespace Ui {
class Statuswindow;
}

namespace s21 {
/**
 * @brief Класс - виджет. На нем отображается информация в режиме реального
 * времени в процессе обучения нейросети.
 */
class Statuswindow : public QWidget {
  Q_OBJECT

 public:
  explicit Statuswindow(QWidget *parent = nullptr);
  ~Statuswindow();
  void append(QString str);
  void moveCursor();
  void insertPlainText(QString s);
  void enable(bool value);
  void setTime(QTime value);

 private slots:
  void on_cancel_clicked();

 public:
  Ui::Statuswindow *ui;
};

}  // namespace s21
#endif  // CPP7_MLP_2_SRC_VIEW_STATUSWINDOW_STATUSWINDOW_H_
