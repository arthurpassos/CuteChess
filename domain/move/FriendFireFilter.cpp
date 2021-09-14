//
// Created by Passos, Arthur on 27/11/20.
//

#include "FriendFireFilter.h"

std::vector<Move> FriendFireFilter::filter(const std::vector <Move> &moves, const Board &board) {
    std::vector<Move> ret;

    // this doesn't make a lot of sense, but at this point, I don't really care.
    // it should be remove_if, since it's filtering.
    std::copy_if(moves.begin(), moves.end(), std::back_inserter(ret), [&](const Move& move) {
        if(board.isInBoard(move.from) && board.isInBoard(move.to)) {
            auto srcSquare = board.matrix[move.from.i][move.from.j];
            auto dstSquare = board.matrix[move.to.i][move.to.j];

            return !dstSquare || srcSquare->getColor() != dstSquare->getColor();
        }

        return false;
    });

    return ret;
}
