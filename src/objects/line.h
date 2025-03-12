#ifndef LINE_H
#define LINE_H

#include "objects/gameobject.h"

#include <cstdint>
#include <qcolor.h>
#include <qlabel.h>

class Line : public GameObject, public QLabel
{
public:
enum class CornerType : uint8_t {
  LeftTopCorner,
  RigtTopCorner,
  LeftBottomCorner,
  RightBottomCorner
};

enum class DashType : uint8_t {
  Vertical,
  Horizontal
};

enum class LineForm : uint8_t {
  Corner,
  Dash
};

union Line_Type {
  enum DashType dash;
  enum CornerType corner;
};

  Line(LineForm, DashType);
  Line(LineForm, CornerType);

private:
  QColor color_;
  LineForm line_form_;
  uint line_width_ = 5;
};

#endif // LINE_H
