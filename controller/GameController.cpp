//
// Created by Passos, Arthur on 23/11/20.
//

#include "GameController.h"
#include <QLayout>
#include <iostream>

GameController::GameController(std::unique_ptr<IGame> game)
: game(std::move(game)) {
}

void GameController::setup() {

    scene.setup(game->getBoard());

    QObject::connect(&scene, &GameScene::requestMove, this, &GameController::handleMoveRequest);
    QObject::connect(&scene, &GameScene::requestPossibleMoves, this, &GameController::handlePossibleMovesRequest);

    view.setScene(&scene);
    setCentralWidget(&view);
}

void GameController::switchTurn() {
    //view.rotate(180);
    scene.switchTurn();
    scene.update();
}

void GameController::boardLoop(std::function<void(int, int)> operation) {
    for(int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            // inverted on purpose
            operation(j, i);
        }
    }
}

void GameController::handleMoveRequest(const Move &move) {
    bool accepted = false;

    game->move(move, [&](bool response) {
        accepted = response;
    });

    if(accepted) {
        scene.move(move);

        switchTurn();
    }
}

void GameController::handlePossibleMovesRequest(const Position &position, std::function<void(std::vector<Move>)> response) {
    response(game->getPossibleMovesForPiece(position));
}
