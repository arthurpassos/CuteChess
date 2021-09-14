//
// Created by Passos, Arthur on 24/11/20.
//

#ifndef CHESS1_QUEEN_H
#define CHESS1_QUEEN_H

#include "PieceBase.h"
#include "Rook.h"
#include "Bishop.h"

namespace pieces {
    class Queen final : public Rook, public Bishop {
    public:
        explicit Queen(Color color);

        [[nodiscard]] std::vector<Move> getPossibleMoves(const Position &position, const Board &board) const override;

        [[nodiscard]] std::shared_ptr<IPiece> clone() const override;

        [[nodiscard]] std::string name() const override;
    };
}


#endif //CHESS1_QUEEN_H
