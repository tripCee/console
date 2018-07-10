#include "mainwindow.h"
#include "operations/helpers.h"
#include "operations/painter.h"
#include "operations/input_handler.h"
#include "objects/All_objects.h"

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


void MainWindow::keyPressEvent(QKeyEvent *event)
{
    printf("KEY PRESS\n");

    Console::Objects::TGame* game = pool.get_game();

    if (!game) return;

    Console::Operations::input_handler op(event->type(), event->key(), QPoint());
    Console::Operations::operate(*game, op, pool);
}


void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    printf("KEY RELEASE\n");

    Console::Objects::TGame* game = pool.get_game();

    if (!game) return;

    Console::Operations::input_handler op(event->type(), event->key(), QPoint());
    Console::Operations::operate(*game, op, pool);

    this->update();
}


void MainWindow::Init_test_game()
{
    object_id_t id = 1;
    float max_width = 0.6;
    uint16_t border_width = 5;

    int board_width = qMin(int(CONSOLE_HEIGHT), qRound(CONSOLE_WIDTH * max_width));
    int block_size = qRound(float(board_width - (2 * border_width)) / 50.0);
    uint16_t turret_size = 4 * block_size;
    int score_width = qRound((float(CONSOLE_WIDTH - board_width) / 2.0));
    int control_height = CONSOLE_HEIGHT - board_width;
    int storage_width = score_width;

    Console::Objects::TGame* game = new Console::Objects::TGame(id, CONSOLE_WIDTH, CONSOLE_HEIGHT, border_width, Qt::black, 1);
    id += 1;
    Console::Objects::TScore* score = new Console::Objects::TScore(id, score_width, CONSOLE_HEIGHT, border_width, Qt::red);
    id += 1;
    Console::Objects::TBoard* board = new Console::Objects::TBoard(id, board_width, board_width, border_width, Qt::white, block_size);
    id += 1;
    Console::Objects::TTurret* turret = new Console::Objects::TTurret(id, turret_size, turret_size, Qt::darkCyan);
    id += 1;
    Console::Objects::TControl* control = new Console::Objects::TControl(id, board_width, control_height, border_width, Qt::green);
    id += 1;
    Console::Objects::TStorage* storage = new Console::Objects::TStorage(id, score_width, CONSOLE_HEIGHT, border_width, Qt::blue);

    //turret->set_gun_direction(45);
    turret->set_gun_rotate_speed(5);

    board->set_weapon_id(turret->get_id());

    game->set_score_id(score->get_id());
    game->set_control_id(control->get_id());
    game->set_storage_id(storage->get_id());
    game->set_weapon_id(turret->get_id());
    game->add_level(board->get_id());

    pool.add_game(game->get_id(), game);
    pool.add_object(score->get_id(), score);
    pool.add_object(board->get_id(), board);
    pool.add_object(turret->get_id(), turret);
    pool.add_object(control->get_id(), control);
    pool.add_object(storage->get_id(), storage);

    this->update();
}
