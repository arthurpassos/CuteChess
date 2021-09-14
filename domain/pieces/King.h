//
// Created by Passos, Arthur on 24/11/20.
//

#ifndef CHESS1_KING_H
#define CHESS1_KING_H

#include "PieceBase.h"

namespace pieces {
    class King final : public PieceBase {
    public:
        explicit King(Color color);

         [[nodiscard]] std::vector<Move> getPossibleMoves(const Position &position, const Board &board) const override;

        [[nodiscard]] std::shared_ptr<IPiece> clone() const override;

        [[nodiscard]] std::string name() const override;
    };
}


#endif //CHESS1_KING_H
