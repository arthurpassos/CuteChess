//
// Created by Passos, Arthur on 23/11/20.
//

#include "LocalGame.h"
#include <range/v3/range.hpp>

LocalGame::LocalGame(std::unique_ptr<IPlayer> p1, std::unique_ptr<IPlayer> p2, LocalGame::Token)
: p1(std::move(p1)), p2(std::move(p2)), whiteTurn(true) {}

const Board & LocalGame::getBoard() {
    return board;
}

void LocalGame::move(const Move &moveRequest, IGame::SimpleResponse response) {
    // I think here would be a good place to implement the command pattern
    if(isMoveRequestValid(moveRequest)) {
        move(moveRequest);
        switchTurn();
        board.recalculateAttackedPositions();
        response(true);
    } else {
        response(false);
    }
}


void LocalGame::move(const Move& moveRequest) {
    const auto& src = moveRequest.from;
    const auto& dst = moveRequest.to;

    board.matrix[dst.i][dst.j] = pieceFromPosition(src);
    board.matrix[src.i][src.j] = nullptr;
}

void LocalGame::switchTurn() {
    whiteTurn = !whiteTurn;
}

Board::PiecePtr LocalGame::pieceFromPosition(const Position& position) {
    return pieceFromPosition(position.i, position.j);
}

bool LocalGame::isMoveRequestValid(const Move &moveRequest) {

    auto possibleMoves = getPossibleMovesForPiece(moveRequest.from);

    const bool canPieceDoIt = std::any_of(possibleMoves.begin(), possibleMoves.end(), [&](const auto& possibleMove) {
        if(possibleMove.to == moveRequest.to) {
            return true;
        }

        return false;
    });

    return canPieceDoIt;
}

std::vector<Move> LocalGame::getPossibleMovesForPiece(const Position &p) {
    if(board.isInBoard(p)) {
        if(const auto piece = board.matrix[p.i][p.j]) {
            auto pieceMoves = piece->getPossibleMoves(p, board);

            std::vector<Move> validMoves;

            for(const auto& pieceMove : pieceMoves) {
                const auto movedPiece = pieceFromPosition(pieceMove.from); // this logic should be in a place the piece can access
                const auto killedPiece = pieceFromPosition(pieceMove.to);
                const auto movingColor = whiteTurn ? pieces::Color::WHITE : pieces::Color::BLACK;

                move(pieceMove);

                board.recalculateAttackedPositions();

                const bool leadToSelfCheck = board.isInCheck(movingColor);

                // restore state
                board.matrix[pieceMove.from.i][pieceMove.from.j] = movedPiece;
                board.matrix[pieceMove.to.i][pieceMove.to.j] = killedPiece;

                board.recalculateAttackedPositions();

                if(!leadToSelfCheck) {
                    validMoves.push_back(pieceMove);
                }
            }

            return validMoves;
        }
    }
    return std::vector<Move>{};
}

Board::PiecePtr LocalGame::pieceFromPosition(int i, int j) {
    return board.matrix[i][j];
}
