//
// Created by Passos, Arthur on 24/11/20.
//

#include "King.h"
#include "../move/FriendFireFilter.h"
#include "../move/AttackedSquaresMoveFilter.h"

namespace pieces {

    King::King(Color color) : PieceBase(color) {}

    std::shared_ptr<IPiece> King::clone() const {
        return std::make_shared<King>(getColor());
    }

    std::string King::name() const {
        return "king";
    }

    std::vector<Move> King::getPossibleMoves(const Position &position, const Board &board) const {
        std::vector<Move> moves;

        const Position up(position.i - 1, position.j);
        moves.emplace_back(position, up);

        const Position down(position.i + 1, position.j);
        moves.emplace_back(position, down);

        const Position right(position.i, position.j + 1);
        moves.emplace_back(position, right);

        const Position left(position.i, position.j - 1);
        moves.emplace_back(position, left);

        const Position upRight(position.i - 1, position.j + 1);
        moves.emplace_back(position, upRight);

        const Position upLeft(position.i - 1, position.j - 1);
        moves.emplace_back(position, upLeft);

        const Position downRight(position.i + 1, position.j + 1);
        moves.emplace_back(position, downRight);

        const Position downLeft(position.i + 1, position.j - 1);
        moves.emplace_back(position, downLeft);

        return FriendFireFilter::filter(AttackedSquaresMoveFilter::filter(moves, board), board);
    }
}