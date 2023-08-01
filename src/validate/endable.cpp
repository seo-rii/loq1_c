#include "../library.h"

Point d[] = {{1,  0},
             {-1, 0},
             {0,  1},
             {0,  -1}};

bool State::bfs(const Point &from, int endY) const {
    bool vis[BOARD_SIZE][BOARD_SIZE] = {};
    Point qu[BOARD_SIZE * BOARD_SIZE] = {};
    int l = 0, r = 0;
    qu[r++] = from;
    vis[from.x() - 1][from.y() - 1] = true;
    while (l < r) {
        auto t = qu[l++];
        if (t.y() == endY) return true;
        for (const auto &i: d) {
            auto p = t + i;
            if (p.x() == 0 || p.x() == BOARD_SIZE - 1 || p.y() == 0 || p.y() == BOARD_SIZE - 1) continue;
            if (vis[p.x() - 1][p.y() - 1]) continue;
            if (!movable(p, t, {})) continue;
            qu[r++] = p;
            vis[p.x() - 1][p.y() - 1] = true;
        }
    }
    return false;
}

bool State::endable() const {
    return bfs(position(), BOARD_SIZE - 1) && bfs(position(false), 0);
}