//
// Created by Passos, Arthur on 24/11/20.
//

#include <unordered_set>
#include <iostream>
#include "GameScene.h"
#include "util/PieceImageFactory.h"

void GameScene::setup(const Board& board) {
    squaresLoop([&](int i, int j) {
        const bool isLight = (i + j) % 2 == 0;
        const auto color = isLight ? QColor(196, 178, 140) : QColor(157, 128, 101);
        squares[i][j] = new SquareItem(color, Position(i, j));

        const auto piece = board.matrix[i][j];
        auto square = squareFromPosition(i, j);

        if(piece) {
            putPiece(piece, Position(i, j));

            const bool isPieceOfCurrentTurn = piece->getColor() == turn;

            if (isPieceOfCurrentTurn) {
                square->setFlag(QGraphicsItem::ItemIsSelectable);
            }
        } else {
            square->setFlag(QGraphicsItem::ItemIsSelectable, false);
        }

        QObject::connect(squares[i][j], &SquareItem::clicked, this, &GameScene::handleSquareClick);

        addItem(squares[i][j]);
    });
}

void GameScene::putPiece(const std::shared_ptr<pieces::IPiece> piece, Position position) {
    const auto image = PieceImageFactory::create(piece);

    if(image.isNull()) {
        return;
    }

    if(auto* square = squareFromPosition(position)) {
        square->setPiece(PieceWithImage(piece, image));
    }
}

SquareItem* GameScene::squareFromPosition(const Position& p) {
    return squareFromPosition(p.i, p.j);
}

void GameScene::switchTurn() {
    if(turn == pieces::Color::WHITE) {
        turn = pieces::Color::BLACK;
    } else {
        turn = pieces::Color::WHITE;
    }

    // should this be here? I guess.
    updateSelectable();
}

void GameScene::squaresLoop(std::function<void(int, int)> operation) {
    for(int i = 0; i < squares.size(); i++) {
        for (int j = 0; j < squares[0].size(); j++) {
            // inverted on purpose
            operation(j, i);
        }
    }
}

void GameScene::updateSelectable() {
    squaresLoop([&](int i, int j) {
        auto* square = squareFromPosition(i, j);
        const bool isPieceOfCurrentTurn = square->hasPiece() && square->getPiece().piece->getColor() == turn;

        if(isPieceOfCurrentTurn) {
            square->setFlag(QGraphicsItem::ItemIsSelectable);
        } else {
            square->setFlag(QGraphicsItem::ItemIsSelectable, false);
        }
    });
}

SquareItem *GameScene::squareFromPosition(int i, int j) {
    return squares[i][j];
}

void GameScene::handleSquareClick(SquareItem *squareItem) {
    clearHighlighted();

    const bool isDifferentSquareThanPrevious = lastSelectedSquare && lastSelectedSquare != squareItem;
    const bool isFriendPiece = squareItem->hasPiece() && squareItem->getPiece().piece->getColor() == turn;

    const auto boundHighlight = std::bind(&GameScene::highlight, this, std::placeholders::_1);

    if(isDifferentSquareThanPrevious) {
        // this logic here is problematic. Once I introduce castling, I'll have to update this.
        const bool isEmptyOrEnemy = !squareItem->hasPiece() || squareItem->getPiece().piece->getColor() != turn;

        if(isEmptyOrEnemy) {
            requestMove(Move{lastSelectedSquare->position, squareItem->position});
            lastSelectedSquare = nullptr;
        } else {
            lastSelectedSquare = squareItem;
            emit requestPossibleMoves(lastSelectedSquare->position, boundHighlight);
        }
    } else if (isFriendPiece) {
        lastSelectedSquare = squareItem;
        emit requestPossibleMoves(lastSelectedSquare->position, boundHighlight);
    } else {
        lastSelectedSquare = nullptr;
    }
    update();
}

void GameScene::move(const Move& move) {
    clearHighlighted();

    const auto srcPos = move.from;
    const auto dstPos = move.to;
    const auto srcSquare = squareFromPosition(srcPos);
    const auto dstSquare = squareFromPosition(dstPos);

    const bool isCapture = dstSquare->hasPiece();

    dstSquare->setPiece(srcSquare->getPiece());
    srcSquare->removePiece();
}

void GameScene::clearHighlighted() {
    for(const auto highlighted : highlightedSquares) {
        highlighted->unhighlight();
    }

    highlightedSquares.clear();
}

void GameScene::highlight(const std::vector<Move>& possibleMoves) {
    for(const auto& move : possibleMoves) {
        auto* toHighlight = squareFromPosition(move.to);
        toHighlight->highlight(toHighlight->hasPiece() ? Qt::red : Qt::green);
        highlightedSquares.push_back(toHighlight);
    }
}
