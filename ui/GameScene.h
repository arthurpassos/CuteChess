//
// Created by Passos, Arthur on 24/11/20.
//

#ifndef CHESS1_GAMESCENE_H
#define CHESS1_GAMESCENE_H


#include <QGraphicsScene>
#include "SquareItem.h"
#include "../domain/Board.h"
#include "../domain/move/Move.h"

class GameScene final : public QGraphicsScene {
Q_OBJECT
public:
    void setup(const Board& board);
    void putPiece(std::shared_ptr<pieces::IPiece> piece, Position position);
    void switchTurn();
    void move(const Move& moveRequest);

    signals:
    void requestMove(const Move& position);
    void requestPossibleMoves(const Position& position, std::function<void(std::vector<Move>)> response);

public slots:
    void handleSquareClick(SquareItem* squareItem);

private:
    std::array<std::array<SquareItem*, Board::COLUMNS>, Board::LINES> squares;
    SquareItem* lastSelectedSquare = nullptr;
    pieces::Color turn;
    std::vector<SquareItem*> highlightedSquares;

    SquareItem* squareFromPosition(const Position& p);
    SquareItem* squareFromPosition(int i, int j);

    void squaresLoop(std::function<void(int, int)> operation);
    void updateSelectable();
    void highlight(const std::vector<Move>& possibleMoves);
    void clearHighlighted();

};

#endif //CHESS1_GAMESCENE_H
