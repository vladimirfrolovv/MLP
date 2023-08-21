#ifndef CPP7_MLP_2_SRC_VIEW_WORKER_WORKER_H_
#define CPP7_MLP_2_SRC_VIEW_WORKER_WORKER_H_

#include <QDebug>
#include <QThread>

#include "../../Controller/controller.h"
#include "../Statuswindow/statuswindow.h"

namespace s21 {
/**
 * @brief Класс, представляющий длительную задачу, которую мы хотим выполнить в
 * отдельном потоке
 */
class Worker : public QObject {
  Q_OBJECT
 public:
  Worker(Statuswindow *status, Controller *controller, size_t epoch,
         size_t hidden_layers, bool crossIsCheck, size_t kgroup,
         std::string path);

 public slots:
  /**
   * @brief Функция выполняется в отдельном потоке.
   */
  void doWork();

 signals:
  void workDone();
  void updateStatus(QString message);

 private slots:
  std::vector<size_t> create_config();

 private:
  Statuswindow *status_{};
  Controller *controller_{};
  size_t epoch_{};
  size_t hidden_layers_{};
  bool crossIsCheck_{};
  size_t kgroup_{};
  std::string path_{};
};
}  // namespace s21
#endif  // CPP7_MLP_2_SRC_VIEW_WORKER_WORKER_H_
