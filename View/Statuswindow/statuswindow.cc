#include "statuswindow.h"

#include "ui_statuswindow.h"

s21::Statuswindow::Statuswindow(QWidget *parent)
    : QWidget(parent), ui(new Ui::Statuswindow) {
  ui->setupUi(this);
  setWindowTitle("Информационная панель");
  ui->textEdit->setReadOnly(true);
}

s21::Statuswindow::~Statuswindow() { delete ui; }

void s21::Statuswindow::append(QString str) { ui->textEdit->append(str); }

void s21::Statuswindow::moveCursor() {
  ui->textEdit->moveCursor(QTextCursor::End);
}

void s21::Statuswindow::insertPlainText(QString s) {
  ui->textEdit->insertPlainText(s);
}

void s21::Statuswindow::on_cancel_clicked() { close(); }

void s21::Statuswindow::enable(bool value) { ui->cancel->setEnabled(value); }

void s21::Statuswindow::setTime(QTime value) {
  ui->label->setText(value.toString("mm:ss"));
}
