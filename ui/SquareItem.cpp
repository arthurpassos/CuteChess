//
// Created by Passos, Arthur on 23/11/20.
//

#include "SquareItem.h"
#include <QPainter>
#include <utility>
#include <QGraphicsSceneMouseEvent>
#include "util/PieceImageFactory.h"

SquareItem::SquareItem(QColor color, Position position)
:  color(std::move(color)), position(position), pieceWithImage(std::nullopt),
    highlightColor(Qt::transparent), highlighted(false) {
}

QRectF SquareItem::boundingRect() const {
    return QRect(position.j * 50, position.i * 50, 50, 50);
}

void SquareItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    static constexpr auto pad = 1;
    auto rect = boundingRect();
    rect.adjust(pad, pad, pad, pad);

    if(isSelected()) {
        painter->setPen(QPen(Qt::black));
    }

    painter->fillRect(rect, highlighted ? highlightColor : color);
    painter->drawRect(rect);

    if(pieceWithImage) {
        painter->drawPixmap(boundingRect().toRect(), pieceWithImage.value().image);
    }
}

void SquareItem::setPiece(PieceWithImage pieceWithImage) {
    this->pieceWithImage = pieceWithImage;
}

bool SquareItem::hasPiece() const {
    return pieceWithImage ? true : false;
}

void SquareItem::removePiece() {
    pieceWithImage = std::nullopt;
}

PieceWithImage SquareItem::getPiece() const {
    return pieceWithImage.value();
}

void SquareItem::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    QGraphicsItem::mousePressEvent(event);

    if(Qt::MouseButton::LeftButton == event->button()) {
        event->accept();
        emit clicked(this);
    } else {
        event->ignore();
    }
}

void SquareItem::highlight(QColor highlightColor) {
    highlighted = true;
    SquareItem::highlightColor = highlightColor;
}

void SquareItem::unhighlight() {
    highlighted = false;
    SquareItem::highlightColor = Qt::transparent;
}