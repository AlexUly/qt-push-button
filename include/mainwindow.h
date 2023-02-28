#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QPushButton>
#include <QWidget>
#include <QPixmap>
#include <QPainter>
#include <QPaintEvent>
#include <QTimer>
#include <QMediaPlayer>
#include <QMediaContent>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class button : public QPushButton{
    Q_OBJECT
public:
   QPixmap current;
   QPixmap up;
   QPixmap down;
   QMediaPlayer seff;
   void paintEvent(QPaintEvent *e) override;

public slots:
    void setUp();
    void setDown();
    void playing();

public:
    button(QWidget *parent){
        setParent(parent);
        current = QPixmap("content/1.png");
        up = QPixmap("content/1.png");
        down = QPixmap("content/2.png");
        seff.setMedia(QUrl::fromLocalFile("content/clicked.mp3"));
        seff.setVolume(50);
        setGeometry(current.rect());
        QPainter p(this);
        p.drawPixmap(0, 0, current);
        connect(this, &QPushButton::clicked, this, &button::setDown);
        connect(this, &QPushButton::clicked, this, &button::playing);
    }
    bool isUp = true;
};



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr){
    };
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
