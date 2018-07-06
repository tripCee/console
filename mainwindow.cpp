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
    uint16_t id = 1;
    float max_width = 0.6;

    int board_width = qMin(int(CONSOLE_HEIGHT), qRound(CONSOLE_WIDTH * max_width));
    int score_width = qRound((float(CONSOLE_WIDTH - board_width) / 2.0));


    Console::Objects::TGame* game = new Console::Objects::TGame(id, CONSOLE_WIDTH, CONSOLE_HEIGHT, Qt::black, 1);
    id += 1;
    Console::Objects::TScore* score = new Console::Objects::TScore(id, score_width, CONSOLE_HEIGHT, Qt::red);
    id += 1;
    Console::Objects::TBoard* board = new Console::Objects::TBoard(id, board_width, board_width, Qt::white, 10);

    game->set_score_id(score->get_id());
    game->add_child(board->get_id());

    pool.add_game(game->get_id(), game);
    pool.add_object(score->get_id(), score);
    pool.add_object(board->get_id(), board);

    printf("pool 1 -> %p\n", pool.get_object(1));
    printf("pool 2 -> %p\n", pool.get_object(2));
    printf("pool 3 -> %p\n", pool.get_object(3));

    this->update();
}
