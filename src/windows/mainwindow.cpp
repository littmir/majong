#include "src/windows/mainwindow.h"

#include "objects/card.h"

#include <qgridlayout.h>
#include <qhashfunctions.h>

MainWindow::MainWindow() : grid_(new QGridLayout(this))
{
  CreateCards();
  CreateBorders();

  for (auto &card : cards_) {
    connect(&card, &Card::clicked, this, &MainWindow::ProcessCard);
  }
}

void
MainWindow::CreateCards()
{
  uint raw = 1;
  uint column = 1;
  for (uint i = 0; i < CARD_COUNT; ++i) {
    grid_->addWidget(&cards_.at(i),
      static_cast<int>(raw), static_cast<int>(column));
    cards_.at(i).setText(QString::number(raw) + ", " + QString::number(column));
    cards_.at(i).SetPosition(static_cast<int>(raw), static_cast<int>(column));
    column++;
    if (column == FIELD_SIZE + 1) {
      column = 1;
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

  // check active card count
  // and make inactive current selection if active cards more than 2
  if (active_card_count_ > 2) {
    card->SetInactive();
    active_card_count_--;
  }

  // save active cards pair
  switch (active_card_count_) {
    case 1:
      active_cards_pair_.first = card;
      break;
    case 2:
      active_cards_pair_.second = card;
      break;
    default:
      active_cards_pair_ = {nullptr, nullptr};
  }
}

void
MainWindow::CreateBorders()
{
  uint raw = 0;
  uint column = 0;
  for (uint i = 0; i < BORDER_CARD_COUNT; ++i) {
    while (raw != 0 && raw != (FRAME_SIZE - 1)
           && column != 0 && column != (FRAME_SIZE - 1)) {
      column++;
    }
    grid_->addWidget(&borders_.at(i),
      static_cast<int>(raw), static_cast<int>(column));
    borders_.at(i).setFixedSize(CARD_SIZE, CARD_SIZE);
    borders_.at(i).setText(QString::number(raw)
      + ", " + QString::number(column));
    column++;
    if (column == FRAME_SIZE) {
      column = 0;
      raw++;
    }
  }
}
