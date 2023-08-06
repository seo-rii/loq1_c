#ifndef LOQ1_LIBRARY_H
#define LOQ1_LIBRARY_H

#include "block/block.h"

const int BOARD_SIZE = 9;
const int I_COUNT = 7;
const int L_COUNT = 3;

unsigned char abs(unsigned char x);

unsigned char max(unsigned char x, unsigned char y);

unsigned char min(unsigned char x, unsigned char y);

class State {
    Point k, p;
    LBlock block_lk[L_COUNT], block_lp[L_COUNT];
    IBlock block_ik[I_COUNT], block_ip[I_COUNT];
    bool turn;

    // State

    State *act(int type, int p1, int p2, int p3 = 0);

    State *copy() { return new State(*this); }

    State *move(const Point &to) const;

    State *placeI(const IBlock &iBlock) const;

    State *placeL(const LBlock &lBlock) const;

    // Utils

    bool movable(const Point &to, const Point &from, const Point &op) const;

    bool bfs(const Point &from, int endY) const;

    Point position(bool my = true) const;

    bool endable() const;

    bool v_block(const Point &lf) const;

    bool h_block(const Point &bt) const;

    bool internal(bool my = true) const;

    bool cross(IBlock iBlock) const;

    bool cross(LBlock iBlock) const;
};

#endif
