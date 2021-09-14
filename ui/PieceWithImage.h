//
// Created by Passos, Arthur on 25/11/20.
//

#ifndef CHESS1_PIECEWITHIMAGE_H
#define CHESS1_PIECEWITHIMAGE_H


#include <QPixmap>
#include "../domain/pieces/IPiece.h"

class PieceWithImage {
public:
    PieceWithImage(const std::shared_ptr<pieces::IPiece> piece, QPixmap image);

    std::shared_ptr<pieces::IPiece> piece;
    QPixmap image;
};


#endif //CHESS1_PIECEWITHIMAGE_H
