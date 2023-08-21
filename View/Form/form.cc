#include "form.h"

s21::Form::Form(QWidget *parent) : QWidget{parent} {
  controller = s21::Controller::GetInstance();
}

void s21::Form::paintEvent(QPaintEvent *) {
  QPainter painter(this);
  painter.drawPixmap(0, 0, m_pixmap);
}

void s21::Form::resizeEvent(QResizeEvent *) {
  auto newRect = m_pixmap.rect().united(rect());
  if (newRect != m_pixmap.rect()) {
    QPixmap newPixmap{newRect.size()};
    QPainter painter{&newPixmap};
    painter.fillRect(newPixmap.rect(), Qt::white);
    painter.drawPixmap(0, 0, m_pixmap);
    m_pixmap = newPixmap;
  }
}

void s21::Form::mousePressEvent(QMouseEvent *ev) {
  if (ev->button() == Qt::RightButton) {
    clearWindow();
  } else {
    m_lastPos = ev->pos();
    draw(ev->pos());
  }
}

void s21::Form::mouseMoveEvent(QMouseEvent *ev) {
  if (ev->buttons() & Qt::LeftButton) draw(ev->pos());
}

void s21::Form::clearWindow() {
  QPainter painter{&m_pixmap};
  painter.eraseRect(this->rect());
  update();
}

void s21::Form::draw(const QPoint &pos) {
  QPainter painter{&m_pixmap};
  painter.setRenderHint(QPainter::Antialiasing);
  QPen pen;
  pen.setWidth(15.0);
  pen.setColor(Qt::black);
  pen.setCapStyle(Qt::FlatCap);
  pen.joinStyle();
  painter.setPen(pen);
  painter.drawEllipse(m_lastPos, 10, 10);

  m_lastPos = pos;
  update();
  SavePixels();
}

void s21::Form::SavePixels() {
  QImage img;
  img = m_pixmap.toImage();
  img = img.scaled(28, 28);
  img = img.transformed(QTransform().rotate(-90));

  QPixmap pxDst(img.size());
  pxDst.fill(Qt::transparent);
  {
    QPainter painter(&pxDst);
    qt_blurImage(&painter, img, 4, true, false);
  }

  std::vector<float> Pixels;
  Pixels.push_back(-1);
  for (int i = pxDst.toImage().size().width() - 1; i >= 0; i--) {
    for (int j = 0; j < pxDst.toImage().size().height(); j++) {
      Pixels.push_back(pxDst.toImage().pixelColor(j, i).black() / 255.f);
    }
  }
  controller->TestOneLetter(Pixels);
}
