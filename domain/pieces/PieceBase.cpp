//
// Created by Passos, Arthur on 24/11/20.
//

#include "PieceBase.h"

namespace pieces {
    PieceBase::PieceBase(Color color)
    : color(color) {
    }

    Color PieceBase::getColor() const {
        return color;
    }
}
