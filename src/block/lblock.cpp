#include "./block.h"

bool LBlock::h_block(const Point &bt) const {
    unsigned char x = bt.x(), y = bt.y(), px = p.x(), py = p.y();
    if (dir == 3 || dir == 4) ++px;
    return px == x && py == y;
}

bool LBlock::v_block(const Point &lf) const {
    unsigned char x = lf.x(), y = lf.y(), px = p.x(), py = p.y();
    if (dir == 2 || dir == 3) ++py;
    return px == x && py == y;
}