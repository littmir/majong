#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <array>

#include <qobjectdefs.h>
#include <qpushbutton.h>
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

private:
  QGridLayout *grid_ = nullptr;

  std::array<QPushButton, CARD_COUNT> cards_;

  void
  CreateCards();
};
#endif // MAINWINDOW_H
