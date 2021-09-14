//
// Created by Passos, Arthur on 23/11/20.
//

#ifndef CHESS1_IGAME_H
#define CHESS1_IGAME_H

#include "../domain/Board.h"
#include "../domain/move/Move.h"
#include "../domain/player/IPlayer.h"

struct IGame {
    virtual ~IGame() = default;

    virtual const Board& getBoard() = 0;

    using SimpleResponse = std::function<void(bool)>;

    virtual void move(const Move& move, SimpleResponse response) = 0;

    virtual std::vector<Move> getPossibleMovesForPiece(const Position& p) = 0;

};

#endif //CHESS1_IGAME_H
