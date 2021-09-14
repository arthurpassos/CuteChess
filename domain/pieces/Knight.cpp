//
// Created by Passos, Arthur on 24/11/20.
//

#include "Knight.h"
#include "../move/FriendFireFilter.h"

namespace pieces {
    Knight::Knight(Color color) : PieceBase(color) {}

    std::shared_ptr<IPiece> Knight::clone() const {
        return std::make_shared<Knight>(getColor());
    }

    std::string Knight::name() const {
        return "knight";
    }

    std::vector<Move> Knight::getPossibleMoves(const Position &position, const Board &board) const {

        std::vector<Move> moves;
        const auto jumpIncrement = 2;
        const auto captureIncrement = 1;

        const Position upRight(position.i - jumpIncrement, position.j + captureIncrement);
        moves.emplace_back(position, upRight);

        const Position upLeft(position.i - jumpIncrement, position.j - captureIncrement);
        moves.emplace_back(position, upLeft);

        const Position downRight(position.i + jumpIncrement, position.j + captureIncrement);
        moves.emplace_back(position, downRight);

        const Position downLeft(position.i + jumpIncrement, position.j - captureIncrement);
        moves.emplace_back(position, downLeft);

        const Position rightUp(position.i - captureIncrement, position.j + jumpIncrement);
        moves.emplace_back(position, rightUp);

        const Position rightDown(position.i + captureIncrement, position.j + jumpIncrement);
        moves.emplace_back(position, rightDown);

        const Position leftUp(position.i - captureIncrement, position.j - jumpIncrement);
        moves.emplace_back(position, leftUp);

        const Position leftDown(position.i + captureIncrement, position.j - jumpIncrement);
        moves.emplace_back(position, leftDown);

        return FriendFireFilter::filter(moves, board);
    }
}
