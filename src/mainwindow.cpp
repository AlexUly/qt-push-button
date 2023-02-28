#include "mainwindow.h"



void button::paintEvent(QPaintEvent *event) {
    QPainter p(this);
    p.drawPixmap(event->rect() ,current);
}

void button::setUp(){
    current = up;
    update();
}

void button::setDown(){
    current = down;
    update();
    QTimer::singleShot(100, this, &button::setUp);
}

void button::playing(){
    seff.play();
}
