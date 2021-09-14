//
// Created by Passos, Arthur on 24/11/20.
//

#ifndef CHESS1_BISHOP_H
#define CHESS1_BISHOP_H

#include "PieceBase.h"

namespace pieces {
    class Bishop : virtual public PieceBase {
    public:
        explicit Bishop(Color color);

        [[nodiscard]] std::vector<Move> getPossibleMoves(const Position &position, const Board &board) const override;

        [[nodiscard]] std::shared_ptr<IPiece> clone() const override;

        [[nodiscard]] std::string name() const override;

    protected:
        [[nodiscard]] std::vector<Move> getRightDiagonalMoves(const Position &position, const Board &board) const;
        [[nodiscard]] std::vector<Move> getLeftDiagonalMoves(const Position &position, const Board &board) const;
    };
}


#endif //CHESS1_BISHOP_H
