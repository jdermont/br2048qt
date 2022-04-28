#include "track.h"

Track::Track(QWidget *parent) : QWidget(parent) {

}

void Track::paintEvent(QPaintEvent *event) {
    QWidget::paintEvent(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    QRect rect = event->rect();
    painter.fillRect(rect,QColor("#FFFFFF"));

//    static QPen white(QColor("#FFFFFF"), 1, Qt::SolidLine, Qt::RoundCap);
//    static QPen gray(QColor("#7F7F7F"), 1, Qt::SolidLine, Qt::RoundCap);
    static QPen black(QColor("#000000"), 1, Qt::SolidLine, Qt::RoundCap);
//    static QPen blue(QColor("#0000FF"), 1, Qt::SolidLine, Qt::RoundCap);
//    QFont font;
//    font.setPixelSize(320 / SCALE);
//    painter.setFont(font);

    Game game;

    painter.setPen(black);
//    painter.drawEllipse(QPoint(0,0),(int)(game.center.radius/SCALE),(int)(game.center.radius/SCALE));

    painter.drawEllipse(QPointF(game.center.x/SCALE,game.center.y/SCALE),600/SCALE,600/SCALE);

}
