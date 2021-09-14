//
// Created by Passos, Arthur on 24/11/20.
//

#include <iostream>
#include "PieceImageFactory.h"
#include "../../lib/magic_enum.h"

std::unordered_map<std::string, QPixmap> PieceImageFactory::cache;

QPixmap PieceImageFactory::create(std::shared_ptr<pieces::IPiece> piece) {

    if(!piece) {
        return QPixmap{};
    }

    const std::string imageKey = std::string(magic_enum::enum_name(piece->getColor())) + "/" + piece->name();

    if(cache.contains(imageKey)) {
        return cache[imageKey];
    }

    const std::string path = prefix() + imageKey;
    QPixmap image(QString::fromStdString(path));

    cache[imageKey] = image;

    return image;
}

std::string PieceImageFactory::prefix() {
    return "/Users/pssrth/CLionProjects/Chess1/resources/images/";
}
