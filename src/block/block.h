#ifndef LOQ0_BLOCK_H
#define LOQ0_BLOCK_H

class Point {
    unsigned char t{};

public:
    Point() = default;

    Point(Point const &p) { t = p.t; }

    Point(int x, int y) { t = (x << 4) | y; }

    [[nodiscard]] unsigned char x() const;

    [[nodiscard]] unsigned char y() const;

    void set(int x, int y) { t = (x << 4) | y; }

    void setX(int x) { t = (x << 4) | y(); }

    void setY(int y) { t = (x() << 4) | y; }

    [[nodiscard]] unsigned char distance(const Point &p) const;

    Point operator+(const Point &p) const { return {x() + p.x(), y() + p.y()}; }

    bool operator!() const { return !t; }
};

class IBlock {
public:
    Point p;
    unsigned char dir{};

    IBlock() = default;

    IBlock(IBlock const &b) { p = b.p, dir = b.dir; }

    IBlock(Point p, int dir) { this->p = p, this->dir = dir; }

    IBlock(int x, int y, int dir) { p = Point(x, y), this->dir = dir; }

    IBlock *copy() { return new IBlock(*this); }

    [[nodiscard]] bool h_block(const Point &bt) const;

    [[nodiscard]] bool v_block(const Point &bt) const;

    bool operator!() const { return !p && dir == 0; }
};

class LBlock {
public:
    Point p;
    unsigned char dir{};

    LBlock() = default;

    LBlock(LBlock const &b) { p = b.p, dir = b.dir; }

    LBlock(Point p, int dir) { this->p = p, this->dir = dir; }

    LBlock(int x, int y, int dir) { p = Point(x, y), this->dir = dir; }

    LBlock *copy() { return new LBlock(*this); }

    [[nodiscard]] bool h_block(const Point &bt) const;

    [[nodiscard]] bool v_block(const Point &bt) const;

    bool operator!() const { return !p && dir == 0; }
};

#endif
