#include "./block.h"

bool IBlock::h_block(const Point &bt) const {
    if (dir != 1) return false;
    unsigned char x = bt.x(), y = bt.y(), px = p.x(), py = p.y();
    if (px != x) return false;
    if (py != y && py + 1 != y) return false;
    return true;
}

bool IBlock::v_block(const Point &lf) const {
    if (dir != 2) return false;
    unsigned char x = lf.x(), y = lf.y(), px = p.x(), py = p.y();
    if (py != y) return false;
    if (px != x && px + 1 != x) return false;
    return true;
}