//
// Created by Passos, Arthur on 25/11/20.
//

#include "PieceWithImage.h"

PieceWithImage::PieceWithImage(const std::shared_ptr<pieces::IPiece> piece, QPixmap image)
: piece(piece), image(image) {

}
