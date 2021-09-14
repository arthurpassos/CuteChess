//
// Created by Passos, Arthur on 23/11/20.
//

#include "Board.h"
#include "pieces/Rook.h"
#include "pieces/Bishop.h"
#include "pieces/Knight.h"
#include "pieces/King.h"
#include "pieces/Queen.h"
#include "pieces/Pawn.h"

template <typename PieceType>
Board::PiecePtr makePiece(pieces::Color color) {
    return std::make_shared<PieceType>(color);
}

Board::Board(const Board &other) {
    for(int i = 0; i < LINES; i++) {
        for(int j = 0; j < COLUMNS; j++) {
            if(other.matrix[i][j]) {
                matrix[i][j] = other.matrix[i][j]->clone();
            }
        }
    }
}

Board &Board::operator=(const Board &other) {
    for(int i = 0; i < LINES; i++) {
        for(int j = 0; j < COLUMNS; j++) {
            if(other.matrix[i][j]) {
                matrix[i][j] = other.matrix[i][j]->clone();
            }
        }
    }

    return *this;
}

Board::Board() {
    matrix[BLACK_BASE_RANK][0] = makePiece<pieces::Rook>(pieces::Color::BLACK);
    matrix[BLACK_BASE_RANK][1] = makePiece<pieces::Knight>(pieces::Color::BLACK);
    matrix[BLACK_BASE_RANK][2] = makePiece<pieces::Bishop>(pieces::Color::BLACK);
    matrix[BLACK_BASE_RANK][3] = makePiece<pieces::Queen>(pieces::Color::BLACK);
    matrix[BLACK_BASE_RANK][4] = makePiece<pieces::King>(pieces::Color::BLACK);
    matrix[BLACK_BASE_RANK][5] = makePiece<pieces::Bishop>(pieces::Color::BLACK);
    matrix[BLACK_BASE_RANK][6] = makePiece<pieces::Knight>(pieces::Color::BLACK);
    matrix[BLACK_BASE_RANK][7] = makePiece<pieces::Rook>(pieces::Color::BLACK);

    matrix[WHITE_BASE_RANK][0] = makePiece<pieces::Rook>(pieces::Color::WHITE);
    matrix[WHITE_BASE_RANK][1] = makePiece<pieces::Knight>(pieces::Color::WHITE);
    matrix[WHITE_BASE_RANK][2] = makePiece<pieces::Bishop>(pieces::Color::WHITE);
    matrix[WHITE_BASE_RANK][3] = makePiece<pieces::Queen>(pieces::Color::WHITE);
    matrix[WHITE_BASE_RANK][4] = makePiece<pieces::King>(pieces::Color::WHITE);
    matrix[WHITE_BASE_RANK][5] = makePiece<pieces::Bishop>(pieces::Color::WHITE);
    matrix[WHITE_BASE_RANK][6] = makePiece<pieces::Knight>(pieces::Color::WHITE);
    matrix[WHITE_BASE_RANK][7] = makePiece<pieces::Rook>(pieces::Color::WHITE);

    for(int i = 0; i < COLUMNS; i++) {
        matrix[WHITE_BASE_RANK - 1][i] = makePiece<pieces::Pawn>(pieces::Color::WHITE);
        matrix[BLACK_BASE_RANK + 1][i] = makePiece<pieces::Pawn>(pieces::Color::BLACK);
    }
}

const std::array<Board::PiecePtr, Board::LINES> &Board::operator[](std::size_t index) const {
    return matrix[index];
}

bool Board::isInBoard(const Position &position) const {
    return position.i < LINES && position.j < COLUMNS;
}

void Board::recalculateAttackedPositions() {
    attackedPositions[pieces::Color::WHITE].clear();
    attackedPositions[pieces::Color::BLACK].clear();
    for(int i = 0; i < Board::LINES; i++) {
        for(int j = 0; j < Board::COLUMNS; j++) {
            if (const auto piece = matrix[i][j]) {
                const auto possibleMoves = piece->getPossibleMoves(Position(i, j), *this);
                for (const auto &move : possibleMoves) {
                    const auto attackingColor = piece->getColor() == pieces::Color::WHITE
                            ? pieces::Color::BLACK : pieces::Color::WHITE;
                    attackedPositions[attackingColor].insert(move.to);
                }
            }
        }
    }
}

const std::unordered_map<pieces::Color, std::unordered_set<Position>> &Board::getAttackedPositions() const {
    return attackedPositions;
}

bool Board::isInCheck(pieces::Color color) const {
    static constexpr std::string_view king = "king";
    for(int i = 0; i < Board::LINES; i++) {
        for (int j = 0; j < Board::COLUMNS; j++) {
            if(const auto piece = matrix[i][j]) {
                if(piece->getColor() == color && piece->name() == king) {
                    return attackedPositions.at(color).contains(Position(i, j));
                }
            }
        }
    }

    return false;
}

