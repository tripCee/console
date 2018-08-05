#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "TPool.h"
#include "objects/All_objects.h"

#include <QMainWindow>
#include <QPaintEvent>
#include <QTimer>

const uint16_t CONSOLE_WIDTH = 1024;
const uint16_t CONSOLE_HEIGHT = 800;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void on_held_timer_timeout();
    void on_game_update_timer();

protected:
    virtual void paintEvent(QPaintEvent *event);
    virtual void keyPressEvent(QKeyEvent *event);
    virtual void keyReleaseEvent(QKeyEvent *event);
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);

private:
    TPool pool;
    Console::Objects::TGame *game;
    QTimer *held_timer;
    QTimer *game_update_timer;
    QPoint last_pos;

    void Init_test_game();
    void process_control_event(QEvent::Type type, int key, QPointF pos);
};

#endif // MAINWINDOW_H
