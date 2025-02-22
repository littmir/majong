#include "src/windows/mainwindow.h"

#include "objects/card.h"

#include <qgridlayout.h>
#include <qhashfunctions.h>

MainWindow::MainWindow() : grid_(new QGridLayout(this))
{
  CreateCards();

  for (auto &card : cards_) {
    connect(&card, &Card::clicked, this, &MainWindow::ProcessCard);
  }
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
    cards_.at(i).SetPosition(raw, column);
    column++;
    if (column == FIELD_SIZE) {
      column = 0;
      raw++;
    }
  }
}

void
MainWindow::ProcessCard()
{
  auto *card = dynamic_cast<Card *>(sender());

  // set card status
  if (card->IsActive()) {
    card->SetInactive();
    active_card_count_--;
  } else {
    card->SetActive();
    active_card_count_++;
  }
}
