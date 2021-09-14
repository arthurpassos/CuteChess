//
// Created by Passos, Arthur on 25/11/20.
//

#include "GameLauncher.h"
#include "LocalGame.h"

std::unique_ptr<IGame> GameLauncher::newGame(std::unique_ptr<IPlayer> p1,
                                             std::unique_ptr<IPlayer> p2,
                                             GameLauncher::Type type) {
    return std::make_unique<LocalGame>(std::move(p1), std::move(p2), LocalGame::Token{});
}
