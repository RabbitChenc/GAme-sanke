#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>

#include <QTime>
#include <QTimer>

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

protected:
    void paintEvent(QPaintEvent *event);
    void keyPressEvent(QKeyEvent *event);

private:
    void addTopRectF();
    void addDownRectF();
    void addLeftRectF();
    void addRightRectF();
    void deleteLastRectF();
    bool snakeStrike();
    enum Move{Left,Right,Up,Down};

protected slots:
    void timeOut();
    void rewardTimeOut();

private:
    QList<QRectF> snake;//🐍体
    int snakeNodeWidth = 10;
    int snakeNodeHeight = 10;
    QTimer *timer = NULL;
    QTimer *rewardTimer = NULL;
    int time = 100;
    int moveFlage = Up;//默认运动方向向上
    bool gameOver = false;
    bool gameStart = false;
    QList<QRectF> rewardNode;//奖励节点

};
#endif // MAINWINDOW_H
