//
// Created by Passos, Arthur on 24/11/20.
//

#include "Pawn.h"
#include "../move/FriendFireFilter.h"

namespace pieces {
    Pawn::Pawn(Color color) : PieceBase(color) {

    }

    std::shared_ptr<IPiece> Pawn::clone() const {
        return std::make_shared<Pawn>(getColor());
    }

    std::string Pawn::name() const {
        return "pawn";
    }

    std::vector<Move> Pawn::getPossibleMoves(const Position &position, const Board &board) const {
        std::vector<Move> possibleMoves;

        for(const auto& move : getForwardMoves(position)) {
            const bool isDestinationSquareEmpty = board.isInBoard(move.to) && !board[move.to.i][move.to.j];
            if(isDestinationSquareEmpty) {
                possibleMoves.emplace_back(move);
            }
        }

        for(const auto& move : getCapturingMoves(position)) {
            const bool isDestinationSquareOccupied = board.isInBoard(move.to) && board[move.to.i][move.to.j];
            if(isDestinationSquareOccupied) {
                possibleMoves.emplace_back(move);
            }
        }

        return FriendFireFilter::filter(possibleMoves, board);
    }

    std::vector<Move> Pawn::getForwardMoves(const Position &position) const {
        std::vector<Move> moves;
        const auto currentRank = position.i;

        if(Color::WHITE == color) {
            moves.emplace_back(position, Position(currentRank - 1, position.j));

            const bool isFirstMove = currentRank == 6;
            if(isFirstMove) {
                moves.emplace_back(position, Position(currentRank - 2, position.j));
            }
        } else {
            moves.emplace_back(position, Position(position.i + 1, position.j));

            const bool isFirstMove = currentRank == 1;
            if(isFirstMove) {
                moves.emplace_back(position, Position(currentRank + 2, position.j));
            }
        }

        return moves;
    }

    std::vector<Move> Pawn::getCapturingMoves(const Position &position) const {
        std::vector<Move> moves;
        const uint8_t rankIncrement = Color::WHITE == color ? -1 : 1;
        const auto nextRank = position.i + rankIncrement;

        moves.emplace_back(position, Position(nextRank, position.j + 1));
        moves.emplace_back(position, Position(nextRank, position.j - 1));

        return moves;
    }

}
