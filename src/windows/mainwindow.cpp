#include "src/windows/mainwindow.h"

#include <qgridlayout.h>
#include <qhashfunctions.h>

MainWindow::MainWindow() : grid_(new QGridLayout(this))
{
  CreateCards();
}

void
MainWindow::CreateCards()
{
  unsigned int raw = 0;
  unsigned int column = 0;
  for (unsigned int i = 0; i < CARD_COUNT; ++i) {
    grid_->addWidget(&cards_.at(i),
      static_cast<int>(raw), static_cast<int>(column));
    cards_.at(i).setText(QString::number(raw) + ", " + QString::number(column));
    column++;
    if (column == FIELD_SIZE) {
      column = 0;
      raw++;
    }
  }
}
