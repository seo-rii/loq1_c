#include "library.h"

[[nodiscard]] unsigned char Point::x() const { return t >> 4; }

[[nodiscard]] unsigned char Point::y() const { return t & 0xf; }

unsigned char Point::distance(const Point &r) const {
    return ABS(x() - r.x()) + ABS(y() - r.y());
}