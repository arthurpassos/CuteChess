//
// Created by Passos, Arthur on 24/11/20.
//

#ifndef CHESS1_PAWN_H
#define CHESS1_PAWN_H

#include "PieceBase.h"

namespace pieces {
    class Pawn final : public PieceBase {
    public:
        explicit Pawn(Color color);

        [[nodiscard]] std::vector<Move> getPossibleMoves(const Position &position, const Board &board) const override;

        [[nodiscard]] std::shared_ptr<IPiece> clone() const override;

        [[nodiscard]] std::string name() const override;

    private:
        [[nodiscard]] std::vector<Move> getCapturingMoves(const Position& position) const;
        [[nodiscard]] std::vector<Move> getForwardMoves(const Position& position) const;
    };
}


#endif //CHESS1_PAWN_H
