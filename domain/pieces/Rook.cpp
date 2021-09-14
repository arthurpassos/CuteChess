//
// Created by Passos, Arthur on 24/11/20.
//

#include "Rook.h"

namespace pieces {
    Rook::Rook(Color color) : PieceBase(color) {}

    std::shared_ptr<IPiece> Rook::clone() const {
        return std::make_shared<Rook>(getColor());
    }

    std::string Rook::name() const {
        return "rook";
    }

    std::vector<Move> Rook::getPossibleMoves(const Position &position, const Board &board) const {
        std::vector<Move> moves;
        auto horizontalMoves = getHorizontalMoves(position, board);
        auto verticalMoves = getVerticalMoves(position, board);

        moves.insert(moves.end(), std::make_move_iterator(horizontalMoves.begin()), std::make_move_iterator(horizontalMoves.end()));

        moves.insert(moves.end(), std::make_move_iterator(verticalMoves.begin()), std::make_move_iterator(verticalMoves.end()));

        return moves;
    }

    std::vector<Move> Rook::getHorizontalMoves(const Position &position, const Board &board) const {
        std::vector<Move> moves;

        // right
        for(int j = position.j + 1; j < Board::COLUMNS; j++) {
            const auto piece = board[position.i][j];

            if(piece) {
                if(piece->getColor() != color) {
                    moves.emplace_back(position, Position(position.i, j));
                }
                break;
            }

            moves.emplace_back(position, Position(position.i, j));
        }

        // left
        for(int j = position.j - 1; j >= 0; j--) {
            const auto piece = board[position.i][j];

            if(piece) {
                if (piece->getColor() != color) {
                    moves.emplace_back(position, Position(position.i, j));
                }
                break;
            }

            moves.emplace_back(position, Position(position.i, j));
        }

        return moves;
    }

    std::vector<Move> Rook::getVerticalMoves(const Position &position, const Board &board) const {
        std::vector<Move> moves;

        // downwards
        for(int i = position.i + 1; i < Board::LINES; i++) {
            const auto piece = board[i][position.j];

            if(piece) {
                if (piece->getColor() != color) {
                    moves.emplace_back(position, Position(i, position.j));
                }
                break;
            }

            moves.emplace_back(position, Position(i, position.j));
        }

        // upwards
        for(int i = position.i - 1; i >= 0; i--) {
            const auto piece = board[i][position.j];

            if(piece) {
                if (piece->getColor() != color) {
                    moves.emplace_back(position, Position(i, position.j));
                }
                break;
            }

            moves.emplace_back(position, Position(i, position.j));
        }

        return moves;
    }
}
