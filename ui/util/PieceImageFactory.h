//
// Created by Passos, Arthur on 24/11/20.
//

#ifndef CHESS1_PIECEIMAGEFACTORY_H
#define CHESS1_PIECEIMAGEFACTORY_H


#include <QPixmap>
#include <unordered_map>
#include "../../domain/pieces/IPiece.h"

class PieceImageFactory {
public:
    static QPixmap create(std::shared_ptr<pieces::IPiece> piece);

private:
    static std::unordered_map<std::string, QPixmap> cache;
    static std::string prefix();
};


#endif //CHESS1_PIECEIMAGEFACTORY_H
