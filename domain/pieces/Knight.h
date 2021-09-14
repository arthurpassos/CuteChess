//
// Created by Passos, Arthur on 24/11/20.
//

#ifndef CHESS1_KNIGHT_H
#define CHESS1_KNIGHT_H

#include "PieceBase.h"

namespace pieces {
    class Knight final : public PieceBase {
    public:
        explicit Knight(Color color);

        [[nodiscard]] std::vector<Move> getPossibleMoves(const Position &position, const Board &board) const override;

        [[nodiscard]] std::shared_ptr<IPiece> clone() const override;

        [[nodiscard]] std::string name() const override;
    };
}


#endif //CHESS1_KNIGHT_H
