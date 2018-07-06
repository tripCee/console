#ifndef PAINTER_H
#define PAINTER_H

#include "TPool.h"
#include "objects/TObject.h"
#include "objects/TGame.h"
#include "objects/board/TBoard.h"
#include "objects/control/TControl.h"
#include "objects/storage/TStorage.h"

#include <QPainter>
#include <QImage>
#include <QPoint>
#include <QRect>

namespace Console {
namespace Operations {

class painter : public QPainter
{
public:
    painter(QPaintDevice *device):
        QPainter(device)
    {}

};


template<class OBJ, class PAINT, typename ...Args> 
void operate_obj(OBJ& obj, PAINT& p, TPool& pool, QPoint offset)
{
    printf("***paint default\n");
}


template<class OBJ, class PAINT, typename ...Args> 
void operate_obj(Console::Objects::TGame& obj, PAINT& p, TPool& pool, QPoint offset)
{
    printf("***paint GAME %d\n", obj.get_id());

    p.fillRect(offset.x(), offset.y(), obj.get_width(), obj.get_height(), obj.get_bg_colour());

    // Score
    auto score = pool.get_object(obj.get_score_id());
    if (score) operate(*score, p, pool, offset);

    // Board FIXME: Use level
    offset += QPoint(score ? score->get_width() : 0, 0);
    auto board = pool.get_object(obj.get_current_board_id());
    if (board) operate(*board, p, pool, offset);
    //operate_children(obj.get_children(), p, pool, offset);

    // Control
    offset += QPoint(0, board ? board->get_height() : 0);
    auto control = pool.get_object(obj.get_control_id());
    if (control) operate(*control, p, pool, offset);

    // Storage
    offset += QPoint(board ? board->get_width() : 0, 0 - (board ? board->get_height() : 0));
    auto storage = pool.get_object(obj.get_storage_id());
    if (storage) operate(*storage, p, pool, offset);
}


template<class OBJ, class PAINT, typename ...Args> 
void operate_obj(Console::Objects::TScore& obj, PAINT& p, TPool& pool, QPoint offset)
{
    printf("***paint SCORE %d %dx%d %d,%d\n", obj.get_id(), obj.get_width(), obj.get_height(), offset.x(), offset.y());

    p.fillRect(offset.x(), offset.y(), obj.get_width(), obj.get_height(), obj.get_bg_colour());
    operate_children(obj.get_children(), p, pool, offset);
}


template<class OBJ, class PAINT, typename ...Args> 
void operate_obj(Console::Objects::TBoard& obj, PAINT& p, TPool& pool, QPoint offset)
{
    printf("***paint BOARD %d %dx%d %d,%d\n", obj.get_id(), obj.get_width(), obj.get_height(), offset.x(), offset.y());

    p.fillRect(offset.x(), offset.y(), obj.get_width(), obj.get_height(), obj.get_bg_colour());

    // Grid
    int start = offset.x();
    int end = offset.x() + obj.get_width();
    int increment = obj.get_block_size();
    int bottom = offset.y() + obj.get_height();
    for (int i = start; i < end; i += increment)
    {
        p.drawLine(QPoint(i, offset.y()), QPoint(i, bottom));
    }

    operate_children(obj.get_children(), p, pool, offset);
}


template<class OBJ, class PAINT, typename ...Args> 
void operate_obj(Console::Objects::TControl& obj, PAINT& p, TPool& pool, QPoint offset)
{
    printf("***paint CONTROL %d %dx%d %d,%d\n", obj.get_id(), obj.get_width(), obj.get_height(), offset.x(), offset.y());

    p.fillRect(offset.x(), offset.y(), obj.get_width(), obj.get_height(), obj.get_bg_colour());
    operate_children(obj.get_children(), p, pool, offset);
}


template<class OBJ, class PAINT, typename ...Args> 
void operate_obj(Console::Objects::TStorage& obj, PAINT& p, TPool& pool, QPoint offset)
{
    printf("***paint STORAGE %d %dx%d %d,%d\n", obj.get_id(), obj.get_width(), obj.get_height(), offset.x(), offset.y());

    p.fillRect(offset.x(), offset.y(), obj.get_width(), obj.get_height(), obj.get_bg_colour());
    operate_children(obj.get_children(), p, pool, offset);
}


} // namespace Operations
} // namespace Console

#endif // PAINTER_H
