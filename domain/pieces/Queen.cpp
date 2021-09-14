//
// Created by Passos, Arthur on 24/11/20.
//

#include "Queen.h"

namespace pieces {

    Queen::Queen(Color color) : Rook(color), Bishop(color), PieceBase(color) {}

    std::shared_ptr<IPiece> Queen::clone() const {
        return std::make_shared<Queen>(getColor());
    }

    std::string Queen::name() const {
        return "queen";
    }

    std::vector<Move> Queen::getPossibleMoves(const Position &position, const Board &board) const {
        std::vector<Move> moves;

        auto rookMoves = Rook::getPossibleMoves(position, board);
        auto bishopMoves = Bishop::getPossibleMoves(position, board);

        moves.insert(moves.end(), std::make_move_iterator(rookMoves.begin()), std::make_move_iterator(rookMoves.end()));

        moves.insert(moves.end(), std::make_move_iterator(bishopMoves.begin()), std::make_move_iterator(bishopMoves.end()));

        return moves;
    }
}