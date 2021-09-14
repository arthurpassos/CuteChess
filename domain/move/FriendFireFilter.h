//
// Created by Passos, Arthur on 27/11/20.
//

#ifndef CHESS1_FRIENDFIREFILTER_H
#define CHESS1_FRIENDFIREFILTER_H

#include <vector>
#include "Move.h"
#include "../Board.h"

class FriendFireFilter {
public:
    static std::vector<Move> filter(const std::vector<Move>& moves, const Board& board);
};


#endif //CHESS1_FRIENDFIREFILTER_H
