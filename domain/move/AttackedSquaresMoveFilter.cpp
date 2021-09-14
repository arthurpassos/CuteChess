//
// Created by Passos, Arthur on 27/11/20.
//

#include "AttackedSquaresMoveFilter.h"

std::vector<Move> AttackedSquaresMoveFilter::filter(const std::vector<Move> &moves, const Board &board) {
    std::vector<Move> ret;

    // this doesn't make a lot of sense, but at this point, I don't really care.
    // it should be remove_if, since it's filtering.
    std::copy_if(moves.begin(), moves.end(), std::back_inserter(ret), [&](const Move& move) {
        if(board.isInBoard(move.from)) {
            if(const auto piece = board.matrix[move.from.i][move.from.j]) {
                const auto attackedSquares = board.getAttackedPositions();

                const auto enemyAttackedSquares = attackedSquares.at(piece->getColor());

                for(const auto enemyAttack : enemyAttackedSquares) {
                    if(enemyAttack == move.to) {
                        return false;
                    }
                }
            }

            return true;
        }
    });

    return ret;
}
