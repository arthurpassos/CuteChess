//
// Created by Passos, Arthur on 23/11/20.
//

#ifndef CHESS1_LOCALGAME_H
#define CHESS1_LOCALGAME_H

#include "../domain/Board.h"
#include "../domain/player/IPlayer.h"
#include "IGame.h"

class LocalGame final : public IGame {

    friend class GameLauncher;
    struct Token {};

public:
    LocalGame(std::unique_ptr<IPlayer> p1, std::unique_ptr<IPlayer> p2, Token token);

    /*
     * API
     * */

    const Board & getBoard() override;

    void move(const Move &moveRequest, SimpleResponse response) override;

    std::vector<Move> getPossibleMovesForPiece(const Position &p) override;

private:
    Board board;

    const std::unique_ptr<IPlayer> p1;
    const std::unique_ptr<IPlayer> p2;

    bool whiteTurn;

    void move(const Move& move);
    void switchTurn();
    bool isMoveRequestValid(const Move& moveRequest);

    Board::PiecePtr pieceFromPosition(const Position& position);
    Board::PiecePtr pieceFromPosition(int i, int j);
};


#endif //CHESS1_LOCALGAME_H
