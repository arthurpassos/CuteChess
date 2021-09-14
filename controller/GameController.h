//
// Created by Passos, Arthur on 23/11/20.
//

#ifndef CHESS1_GAMECONTROLLER_H
#define CHESS1_GAMECONTROLLER_H


#include <memory>
#include <QMainWindow>
#include <QGraphicsView>
#include "../game/IGame.h"
#include "../domain/Position.h"
#include "../ui/GameScene.h"
#include "../domain/player/IPlayer.h"

class GameController : public QMainWindow {
    Q_OBJECT

public:
    explicit GameController(std::unique_ptr<IGame> game);

    void setup();

    public slots:
    void handleMoveRequest(const Move &move);
    void handlePossibleMovesRequest(const Position& position, std::function<void(std::vector<Move>)> response);

private:
    std::unique_ptr<IGame> game;
    QGraphicsView view;
    GameScene scene;

    void switchTurn();
    void rotate();
    void updateSelection();

    static void boardLoop(std::function<void(int, int)> operation);
};


#endif //CHESS1_GAMECONTROLLER_H
