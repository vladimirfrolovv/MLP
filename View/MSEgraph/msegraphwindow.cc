#include "msegraphwindow.h"

#include "ui_msegraphwindow.h"

s21::Msegraphwindow::Msegraphwindow(QWidget *parent)
    : QWidget(parent), ui(new Ui::msegraphwindow) {
  ui->setupUi(this);
  controller = s21::Controller::GetInstance();
}

s21::Msegraphwindow::~Msegraphwindow() { delete ui; }

void s21::Msegraphwindow::PrintGraph() {
  ui->widget->clearGraphs();

  double y_min = 0.0;
  double y_max = *std::max_element(controller->GetMseForGraph().begin(),
                                   controller->GetMseForGraph().end()) +
                 0.5;
  double x_min = 1.0;
  double x_max = controller->GetMseForGraph().size();

  ui->widget->xAxis->setRange(x_min, x_max);
  ui->widget->xAxis->setLabel("epochs");

  ui->widget->yAxis->setRange(y_min, y_max);
  ui->widget->yAxis->setLabel("MSE");

  QVector<double> x, y;
  for (int counter = 1; counter <= x_max; ++counter) {
    x.push_back(counter);
  }
  for (int counter = 0; counter < x_max; ++counter) {
    y.push_back(controller->GetMseForGraph()[counter]);
  }

  ui->widget->addGraph();
  ui->widget->graph(0)->addData(x, y);
  ui->widget->replot();
}
