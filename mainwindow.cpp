#include "mainwindow.h"
#include "operations/helpers.h"
#include "operations/painter.h"
#include "objects/TGame.h"
#include "objects/score/TScore.h"
#include "objects/board/TBoard.h"

#include <QPainter>

MainWindow::MainWindow(QWidget *parent): 
    QMainWindow(parent),
    pool()
{
    this->setGeometry(0, 0, CONSOLE_WIDTH, CONSOLE_HEIGHT);
    this->move(100, 100);

    Init_test_game();
}


MainWindow::~MainWindow()
{
    //if (pool) delete pool;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    printf("PAINT\n");
    
    Console::Objects::TGame* game = pool.get_game();

    if (!game) return;

    Console::Operations::painter op(this);
    Console::Operations::operate(*game, op, pool, QPoint(0, 0)); 
}

void MainWindow::Init_test_game()
{
    int id = 1;
    Console::Objects::TGame* game = new Console::Objects::TGame(id, (CONSOLE_WIDTH - CONSOLE_HEIGHT) / 2, CONSOLE_HEIGHT, Qt::black, 1);
    ++id;
    Console::Objects::TScore* score = new Console::Objects::TScore(id, 0, 0, Qt::white);
    ++id;
    Console::Objects::TBoard* board = new Console::Objects::TBoard(id, CONSOLE_HEIGHT, CONSOLE_HEIGHT, Qt::white, 10);
    ++id;

    game->add_score_id(score->get_id());
    game->add_child(board->get_id());

    pool.add_game(game->get_id(), game);
    pool.add_object(score->get_id(), score);
    pool.add_object(board->get_id(), board);

    this->update();
}
