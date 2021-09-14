//
// Created by Passos, Arthur on 23/11/20.
//

#include "Move.h"

Move::Move(const Position &from, const Position &to) : from(from), to(to) {}

bool Move::operator==(const Move &rhs) const {
    return from == rhs.from &&
           to == rhs.to;
}

bool Move::operator!=(const Move &rhs) const {
    return !(rhs == *this);
}
