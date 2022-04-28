#ifndef TRACK_H
#define TRACK_H

#include <QObject>
#include <QWidget>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QPainter>
#include <QRect>
#include <QPen>
#include <QBrush>
#include <QFont>
#include <QFontMetrics>
#include <QThread>

#include "game.h"

#define SCALE 5.0

class Track : public QWidget {
    Q_OBJECT
public:
    explicit Track(QWidget *parent = nullptr);
    virtual void paintEvent(QPaintEvent *);
//    virtual void mouseReleaseEvent(QMouseEvent *);
//    virtual void keyPressEvent(QKeyEvent *);
    //Game game = Game("8179 7909;11727 5704;11009 3026;10111 1169;5835 7503;1380 2538;4716 1269;4025 5146");
//    Game game = Game(15);

    Game game;

private:
};

#endif // TRACK_H
