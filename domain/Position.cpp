//
// Created by Passos, Arthur on 23/11/20.
//

#include "Position.h"

Position::Position(const uint8_t i, const uint8_t j) : i(i), j(j) {}

bool Position::operator==(const Position &other) const {
    return i == other.i && j == other.j;
}
