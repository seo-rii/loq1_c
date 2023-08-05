#include "../library.h"

bool State::movable(const Point &to, const Point &from, const Point &op) const {
    if (to.x() == op.x() && to.y() == op.y()) return false;
    if (to.x() < 0 || to.x() > BOARD_SIZE || to.y() < 0 || to.y() > BOARD_SIZE) return false;
    unsigned char dis = from.distance(to);
    if (dis == 1) {
        if (from.x() == to.x()) {
            if (v_block({from.x(), max(from.y(), to.y())})) return false;
        } else {
            if (h_block({max(from.x(), to.x()), from.y()})) return false;
        }
    } else if (dis == 2) {
        if (from.distance(op) != 1 || op.distance(to) != 1) return false;
        if (from.x() == to.x()) {
            if (v_block({from.x(), max(from.y(), op.y())})) return false;
            if (v_block({from.x(), max(to.y(), op.y())})) return false;
        } else if (from.y() == to.y()) {
            if (h_block({max(from.x(), op.x()), from.y()})) return false;
            if (h_block({max(to.x(), op.x()), from.y()})) return false;
        } else {
            if (from.x() == op.x() && op.y() == to.y()) {
                if (v_block({from.x(), max(from.y(), op.y())})) return false;
                if (h_block({max(to.x(), op.x()), op.y()})) return false;
                if (!v_block({from.x(), op.y() * 2 - from.y()})) return false;
            } else if (from.y() == op.y() && op.x() == to.x()) {
                if (h_block({max(from.x(), op.x()), from.y()})) return false;
                if (v_block({op.x(), max(to.y(), op.y())})) return false;
                if (!h_block({op.x() * 2 - from.x(), from.y()})) return false;
            } else return false;
        }
    }
    return true;
}

State *State::move(const Point &to) const {
    if (!movable(to, position(), position(false))) return nullptr;
    State *ret = new State(*this);
    if (ret->turn) ret->k = to;
    else ret->p = to;
    ret->turn = !ret->turn;
    return ret;
}
