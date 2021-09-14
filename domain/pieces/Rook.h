//
// Created by Passos, Arthur on 24/11/20.
//

#ifndef CHESS1_ROOK_H
#define CHESS1_ROOK_H

#include "PieceBase.h"

namespace pieces {
    class Rook : virtual public PieceBase {
    public:
        explicit Rook(Color color);

        [[nodiscard]] std::shared_ptr<IPiece> clone() const override;

        [[nodiscard]] std::vector<Move> getPossibleMoves(const Position &position, const Board &board) const override;

        [[nodiscard]] std::string name() const override;

    protected:
        [[nodiscard]] std::vector<Move> getHorizontalMoves(const Position &position, const Board &board) const;
        [[nodiscard]] std::vector<Move> getVerticalMoves(const Position &position, const Board &board) const;
    };
}


#endif //CHESS1_ROOK_H
