#ifndef CARD_H
#define CARD_H

#include <utility>

#include <qobjectdefs.h>
#include <qpushbutton.h>

class Card : public QPushButton
{
  Q_OBJECT

public:
  Card();

  void
  SetPosition(unsigned int raw, unsigned int column);

  bool
  IsActive() const;

public slots:
  void
  SetActive();

  void
  SetInactive();

private:
  const unsigned int card_side_size_ = 50;
  bool is_active_ = false;
  std::pair<int, int> position_;
};

#endif // CARD_H
