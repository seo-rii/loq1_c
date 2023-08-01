#include "../library.h"

inline State *State::placeI(const IBlock &iBlock) const {
    if (!iBlock) return nullptr;
    if (iBlock.dir < 1 || iBlock.dir > 2) return nullptr;
    if (this->cross(iBlock)) return nullptr;
    State *state = new State(*this);
    auto target = state->turn ? &state->block_ip : &state->block_ik;
    for (auto &b: *target) {
        if (!b) {
            b = iBlock;
            state->turn = !state->turn;
            return state;
        }
    }
    return nullptr;
}

inline State *State::placeL(const LBlock &lBlock) const {
    if (!lBlock) return nullptr;
    if (this->cross(lBlock)) return nullptr;
    State *state = new State(*this);
    auto target = state->turn ? &state->block_lp : &state->block_lk;
    for (auto &b: *target) {
        if (!b) {
            b = lBlock;
            state->turn = !state->turn;
            return state;
        }
    }
    return nullptr;
}