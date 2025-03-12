#ifndef CARD_H
#define CARD_H

#include "gameobject.h"

#include <qpushbutton.h>

class Card : public GameObject, public QPushButton
{

public:
  Card();

  bool
  IsActive() const;

public slots:
  void
  SetActive();

  void
  SetInactive();

private:
  bool is_active_ = false;
};

#endif // CARD_H
