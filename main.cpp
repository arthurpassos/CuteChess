#include <iostream>
#include <QApplication>
#include "controller/GameController.h"
#include "game/LocalGame.h"
#include "domain/player/Player.h"
#include "game/GameLauncher.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    GameController gameController{
            GameLauncher::newGame(
                std::make_unique<Player>(1, "Arthur"),
                std::make_unique<Player>(2, "Elizabeth"),
                GameLauncher::Type::OFFLINE
            )
    };

    gameController.setup();

    gameController.show();

    return QApplication::exec();
}
