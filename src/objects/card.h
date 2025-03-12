#ifndef CARD_H
#define CARD_H

#include <qobjectdefs.h>
#include <qpushbutton.h>

class Card : public QPushButton
{
  Q_OBJECT

public:
  Card();

private:
  const unsigned int card_side_size_ = 50;
};

#endif // CARD_H
