#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "objects/border.h"
#include "objects/card.h"

#include "common.h"
#include "objects/line.h"

#include <array>
#include <utility>

#include <qobjectdefs.h>
#include <qwidget.h>

/// Size of a one side of the square cards field
constexpr unsigned int FIELD_SIZE = 3;

/// Count of cards
constexpr unsigned int CARD_COUNT = FIELD_SIZE * FIELD_SIZE;

/// Size of the one side of the cards field with borders
constexpr unsigned int FRAME_SIZE = FIELD_SIZE + 2;

/// Count of borders around cards field
constexpr unsigned int BORDER_CARD_COUNT
  = (FRAME_SIZE * FRAME_SIZE) - CARD_COUNT;

class QGridLayout;

class MainWindow : public QWidget
{
  Q_OBJECT

public:
  MainWindow();

public slots:
  void
  ProcessCard();

private:
  QGridLayout *grid_ = nullptr;
  std::pair<Card *, Card *> active_cards_pair_ = {nullptr, nullptr};
  Line *line_ = nullptr;

  std::array<Card, CARD_COUNT> cards_;
  uint active_card_count_ = 0;
  std::array<Border, BORDER_CARD_COUNT> borders_;

  void
  CreateCards();

  void
  CreateBorders();

  void
  DrawLineBetweenCards();
};
#endif // MAINWINDOW_H
