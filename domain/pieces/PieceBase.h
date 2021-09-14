//
// Created by Passos, Arthur on 24/11/20.
//

#ifndef CHESS1_PIECEBASE_H
#define CHESS1_PIECEBASE_H

#include "IPiece.h"
#include "../Board.h"

namespace pieces {
    class PieceBase : public IPiece {
    public:
        explicit PieceBase(Color color);

        [[nodiscard]] Color getColor() const override;

    protected:
        const Color color;
    };
}


#endif //CHESS1_PIECEBASE_H
