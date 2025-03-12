#include "line.h"

#include "common.h"

#include <qline.h>
#include <qnamespace.h>
#include <qpainter.h>
#include <qpicture.h>

Line::Line(LineForm form, DashType dash)
  : color_(Qt::green), line_form_(form)
{
  setFixedSize(CARD_SIZE, CARD_SIZE);

  QPicture pic;
  QPainter painter(&pic);
  painter.setRenderHint(QPainter::Antialiasing);
  painter.setPen(QPen(color_, line_width_, Qt::SolidLine, Qt::RoundCap));
  switch (dash) {
    case DashType::Horizontal:
      painter.drawLine(0, 25, 50, 25);
      break;
    case DashType::Vertical:
      painter.drawLine(25, 0, 25, 50);
      break;
    default:
      break;
  }
  this->setPicture(pic);
}

Line::Line(LineForm form, CornerType corner)
  : color_(Qt::green), line_form_(form)
{
  setFixedSize(CARD_SIZE, CARD_SIZE);

  QPicture pic;
  QPainter painter(&pic);
  painter.setRenderHint(QPainter::Antialiasing);
  painter.setPen(QPen(color_, line_width_, Qt::SolidLine, Qt::RoundCap));
  switch (corner) {
    case CornerType::LeftTopCorner: {
        painter.drawLine(25, 50, 50, 25);
        //painter.drawLine(25, 25, 25, 50);

      //QLine lines[2] = {{50, 50, 0, 0}, {0, 0, 50, 50}};
      //painter.drawLines(lines, 2);
      break;
    }
    default:
      break;
  }
  setPicture(pic);
  setFrameStyle(QFrame::Box);
}
