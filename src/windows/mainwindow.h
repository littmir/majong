#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "objects/card.h"

#include <array>
#include <utility>

#include <qobjectdefs.h>
#include <qwidget.h>

/// Size of a one side of the square cards field
constexpr unsigned int FIELD_SIZE = 3;

/// Count of cards
constexpr unsigned int CARD_COUNT = FIELD_SIZE * FIELD_SIZE;

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

  std::array<Card, CARD_COUNT> cards_;
  unsigned int active_card_count_ = 0;

  void
  CreateCards();
};
#endif // MAINWINDOW_H
