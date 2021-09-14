//
// Created by Passos, Arthur on 24/11/20.
//

#include "Bishop.h"

namespace pieces {

    Bishop::Bishop(Color color) : PieceBase(color) {}

    std::shared_ptr<IPiece> Bishop::clone() const {
        return std::make_shared<Bishop>(getColor());
    }

    std::string Bishop::name() const {
        return "bishop";
    }

    std::vector<Move> Bishop::getPossibleMoves(const Position &position, const Board &board) const {
        std::vector<Move> moves;

        auto leftDiagonalMoves = getLeftDiagonalMoves(position, board);
        auto rightDiagonalMoves = getRightDiagonalMoves(position, board);

        moves.insert(moves.end(), std::make_move_iterator(leftDiagonalMoves.begin()), std::make_move_iterator(leftDiagonalMoves.end()));

        moves.insert(moves.end(), std::make_move_iterator(rightDiagonalMoves.begin()), std::make_move_iterator(rightDiagonalMoves.end()));

        return moves;
    }

    std::vector<Move> Bishop::getLeftDiagonalMoves(const Position &position, const Board &board) const {
        std::vector<Move> moves;

        // upwards
        for(int i = position.i - 1,j = position.j + 1; i >= 0 && j < Board::COLUMNS; i--, j++) {
            const auto piece = board[i][j];

            if(piece) {
                if(piece->getColor() != color) {
                    moves.emplace_back(position, Position(i, j));
                }
                break;
            }

            moves.emplace_back(position, Position(i, j));
        }

        // downwards
        for(int i = position.i + 1,j = position.j - 1; i < Board::LINES && j >= 0; i++, j--) {
            const auto piece = board[i][j];

            if(piece) {
                if (piece->getColor() != color) {
                    moves.emplace_back(position, Position(i, j));
                }
                break;
            }

            moves.emplace_back(position, Position(i, j));
        }

        return moves;
    }

    std::vector<Move> Bishop::getRightDiagonalMoves(const Position &position, const Board &board) const {
        std::vector<Move> moves;

        // upwards
        for(int i = position.i - 1,j = position.j - 1; i >= 0 && j >= 0; i--, j--) {
            const auto piece = board[i][j];

            if(piece) {
                if(piece->getColor() != color) {
                    moves.emplace_back(position, Position(i, j));
                }
                break;
            }

            moves.emplace_back(position, Position(i, j));
        }

        // downwards
        for(int i = position.i + 1,j = position.j + 1; i < Board::LINES && j < Board::COLUMNS; i++, j++) {
            const auto piece = board[i][j];

            if(piece) {
                if (piece->getColor() != color) {
                    moves.emplace_back(position, Position(i, j));
                }
                break;
            }

            moves.emplace_back(position, Position(i, j));
        }

        return moves;
    }
}