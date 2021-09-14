//
// Created by Passos, Arthur on 23/11/20.
//

#ifndef CHESS1_MOVE_H
#define CHESS1_MOVE_H


#include "../Position.h"

class Move {
public:
    Move(const Position &from, const Position &to);

    Position from;
    Position to;

    bool operator==(const Move &rhs) const;

    bool operator!=(const Move &rhs) const;
};


#endif //CHESS1_MOVE_H
