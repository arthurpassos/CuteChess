//
// Created by Passos, Arthur on 27/11/20.
//

#ifndef CHESS1_ATTACKEDSQUARESMOVEFILTER_H
#define CHESS1_ATTACKEDSQUARESMOVEFILTER_H
#include <vector>
#include "Move.h"
#include "../Board.h"

class AttackedSquaresMoveFilter {
public:
    static std::vector<Move> filter(const std::vector<Move>& moves, const Board& board);
};


#endif //CHESS1_ATTACKEDSQUARESMOVEFILTER_H
