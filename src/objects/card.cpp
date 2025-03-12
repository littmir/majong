#include "card.h"

#include "common.h"

Card::Card()
{
  setFixedSize(CARD_SIZE, CARD_SIZE);

  setCheckable(true);
}

void
Card::SetActive()
{
  is_active_ = true;
  setChecked(true);
}

void
Card::SetInactive()
{
  is_active_ = false;
  this->setChecked(false);
}

bool
Card::IsActive() const
{
  return is_active_;
}
