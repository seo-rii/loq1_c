#include "library.h"

inline Point State::position(bool my) const {
    return (!my ^ this->turn) ? this->k : this->p;
}

inline bool State::internal(bool my) const {
    Point p = this->position(my);
    return p.x() > 0 && p.x() < BOARD_SIZE - 1 && p.y() > 0 && p.y() < BOARD_SIZE - 1;
}

inline bool State::v_block(const Point &lf) const {
    if (lf.x() < 1 || lf.x() > BOARD_SIZE || lf.y() < 1 || lf.y() > BOARD_SIZE + 1) return true;
    for (auto &b: this->block_ik) if (b.v_block(lf)) return true;
    for (auto &b: this->block_ip) if (b.v_block(lf)) return true;
    for (auto &b: this->block_lk) if (b.v_block(lf)) return true;
    for (auto &b: this->block_lp) if (b.v_block(lf)) return true;
    return false;
}

inline bool State::h_block(const Point &bt) const {
    if (bt.x() < 1 || bt.x() > BOARD_SIZE + 1 || bt.y() < 1 || bt.y() > BOARD_SIZE) return true;
    for (auto &b: this->block_ik) if (b.h_block(bt)) return true;
    for (auto &b: this->block_ip) if (b.h_block(bt)) return true;
    for (auto &b: this->block_lk) if (b.h_block(bt)) return true;
    for (auto &b: this->block_lp) if (b.h_block(bt)) return true;
    return false;
}

inline bool State::cross(IBlock iBlock) const {
    unsigned char x = iBlock.p.x(), y = iBlock.p.y();
    if (iBlock.dir == 1) {
        if (h_block(iBlock.p)) return true;
        if (h_block({x, y + 1})) return true;
        for (auto &b: this->block_ik)
            if (b.dir == 2 && b.p.x() == x - 1 && b.p.y() == y + 1) return true;
        for (auto &b: this->block_ip)
            if (b.dir == 2 && b.p.x() == x - 1 && b.p.y() == y + 1) return true;
    } else {
        if (v_block(iBlock.p)) return true;
        if (v_block({x + 1, y})) return true;
        for (auto &b: this->block_ik)
            if (b.dir == 1 && b.p.x() == x + 1 && b.p.y() == y - 1) return true;
        for (auto &b: this->block_ip)
            if (b.dir == 1 && b.p.x() == x + 1 && b.p.y() == y - 1) return true;
    }
    return false;
}

inline bool State::cross(LBlock lBlock) const {
    unsigned char x = lBlock.p.x(), y = lBlock.p.y(), ah = 0, av = 0;
    if (lBlock.dir == 3 || lBlock.dir == 4) ah = 1;
    if (lBlock.dir == 3 || lBlock.dir == 2) av = 1;
    if (h_block({x + ah, y})) return true;
    if (v_block({x, y + av})) return true;
    for (auto &b: this->block_lk) {
        auto s = b.dir - lBlock.dir;
        if (s != 2 && s != -2) continue;
        unsigned char bx = b.p.x(), by = b.p.y(), bh = 0, bv = 0;
        if (b.dir == 3 || b.dir == 4) bh = 1;
        if (b.dir == 3 || b.dir == 2) bv = 1;
        if (bx + bh == x + ah && by + bv == y + av) return true;
    }
    for (auto &b: this->block_lp) {
        auto s = b.dir - lBlock.dir;
        if (s != 2 && s != -2) continue;
        unsigned char bx = b.p.x(), by = b.p.y(), bh = 0, bv = 0;
        if (b.dir == 3 || b.dir == 4) bh = 1;
        if (b.dir == 3 || b.dir == 2) bv = 1;
        if (bx + bh == x + ah && by + bv == y + av) return true;
    }
    return false;
}

State *State::act(int type, int p1, int p2, int p3) {
    if (type == 0) return move({p1, p2});
    if (type == 1) return placeI({{p1, p2}, p3});
    if (type == 2) return placeL({{p1, p2}, p3});
    return nullptr;
}