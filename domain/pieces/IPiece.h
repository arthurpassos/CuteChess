//
// Created by Passos, Arthur on 24/11/20.
//

#ifndef CHESS1_IPIECE_H
#define CHESS1_IPIECE_H

#include <string>
#include <vector>
#include "../move/Move.h"

class Board;

namespace pieces {

    enum class Color {
        WHITE,
        BLACK
    };

    struct IPiece {
        virtual ~IPiece() = default;

        [[nodiscard]] virtual std::vector<Move> getPossibleMoves(const Position &position, const Board &board) const = 0;
        [[nodiscard]] virtual Color getColor() const = 0;

        // this is so wrong. I need the name so I can avoid down-casting to get the image file name
        // the problem is that if the image name changes, the name needs to be changed. I don't want this
        [[nodiscard]] virtual std::string name() const = 0;

        [[nodiscard]] virtual std::shared_ptr<IPiece> clone() const = 0;
    };
}

#endif //CHESS1_IPIECE_H
