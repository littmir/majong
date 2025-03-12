#include "card.h"

Card::Card()
{
  setFixedSize(static_cast<int>(card_side_size_),
    static_cast<int>(card_side_size_));
}
