//
// Created by Passos, Arthur on 23/11/20.
//

#ifndef CHESS1_SQUAREITEM_H
#define CHESS1_SQUAREITEM_H


#include <QGraphicsItem>
#include "../domain/Position.h"
#include "../domain/pieces/IPiece.h"
#include "PieceWithImage.h"

class SquareItem : public QObject, public QGraphicsItem {
Q_OBJECT
public:
    SquareItem(QColor color, Position position);

    [[nodiscard]] QRectF boundingRect() const override;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    void setPiece(PieceWithImage pieceWithImage);
    void removePiece();
    void highlight(QColor color);
    void unhighlight();

    [[nodiscard]] PieceWithImage getPiece() const;
    [[nodiscard]] bool hasPiece() const;

    const Position position;

signals:
    void clicked(SquareItem* square);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;


private:
    QColor color;
    QColor highlightColor;
    std::optional<PieceWithImage> pieceWithImage;
    bool highlighted;
};


#endif //CHESS1_SQUAREITEM_H
