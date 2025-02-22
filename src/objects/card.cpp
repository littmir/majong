#include "card.h"

Card::Card()
{
  setFixedSize(static_cast<int>(card_side_size_),
    static_cast<int>(card_side_size_));

  setCheckable(true);

  connect(this, &Card::clicked, this, &Card::SetActive);
}

void
Card::SetActive()
{
  is_active_ = !is_active_;
  setChecked(is_active_);
}
