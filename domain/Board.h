//
// Created by Passos, Arthur on 23/11/20.
//

#ifndef CHESS1_BOARD_H
#define CHESS1_BOARD_H


#include <array>
#include <optional>
#include <unordered_map>
#include "pieces/IPiece.h"

class Board {
    friend class LocalGame;
public:
    static constexpr uint8_t LINES = 8;
    static constexpr uint8_t COLUMNS = 8;
    static constexpr uint8_t WHITE_BASE_RANK = 7;
    static constexpr uint8_t BLACK_BASE_RANK = 0;
    using PiecePtr = std::shared_ptr<pieces::IPiece>;
    using Matrix = std::array<std::array<PiecePtr, LINES>, COLUMNS>;

    Board();

    Board(const Board& other);
    Board& operator=(const Board& other);

    Board(Board&& other) = delete;
    Board& operator=(Board&&) = delete;

    const std::array<PiecePtr, LINES>& operator[](std::size_t index) const;

    [[nodiscard]] bool isInBoard(const Position& position) const;

    [[nodiscard]] const std::unordered_map<pieces::Color, std::unordered_set<Position>> &getAttackedPositions() const;

    [[nodiscard]] bool isInCheck(pieces::Color color) const;

    Matrix matrix;

private:
    std::unordered_map<pieces::Color, std::unordered_set<Position>> attackedPositions;
    void recalculateAttackedPositions();

};


#endif //CHESS1_BOARD_H
