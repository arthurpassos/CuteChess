//
// Created by Passos, Arthur on 25/11/20.
//

#ifndef CHESS1_GAMELAUNCHER_H
#define CHESS1_GAMELAUNCHER_H


#include "IGame.h"
#include "../domain/player/IPlayer.h"

class GameLauncher {
public:
    enum class Type {
        OFFLINE,
        REMOTE
    };

    static std::unique_ptr<IGame> newGame(std::unique_ptr<IPlayer> p1, std::unique_ptr<IPlayer> p2, Type type);
};


#endif //CHESS1_GAMELAUNCHER_H
