#ifndef CARD_H
#define CARD_H

#include <qobjectdefs.h>
#include <qpushbutton.h>

class Card : public QPushButton
{
  Q_OBJECT

public:
  Card();

public slots:
  void
  SetActive();

private:
  const unsigned int card_side_size_ = 50;
  bool is_active_ = false;
};

#endif // CARD_H
