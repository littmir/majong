#include "card.h"

Card::Card()
{
  setFixedSize(static_cast<int>(card_side_size_),
    static_cast<int>(card_side_size_));

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
