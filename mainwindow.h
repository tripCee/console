#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPaintEvent>

#include "TPool.h"

const uint16_t CONSOLE_WIDTH = 1024;
const uint16_t CONSOLE_HEIGHT = 800;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    virtual void paintEvent(QPaintEvent *event);
    virtual void keyPressEvent(QKeyEvent *event);
    virtual void keyReleaseEvent(QKeyEvent *event);

private:
    TPool pool;

    void Init_test_game();
};

#endif // MAINWINDOW_H
