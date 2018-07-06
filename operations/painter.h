#ifndef PAINTER_H
#define PAINTER_H

#include "TPool.h"
#include "objects/TObject.h"
#include "objects/TGame.h"
#include "objects/board/TBoard.h"

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

    //
    offset += QPoint(score ? score->get_width() : 0, 0);
    operate_children(obj.get_children(), p, pool, offset);
}


template<class OBJ, class PAINT, typename ...Args> 
void operate_obj(Console::Objects::TScore& obj, PAINT& p, TPool& pool, QPoint offset)
{
    printf("***paint SCORE %d\n", obj.get_id());

    p.fillRect(offset.x(), offset.y(), obj.get_width(), obj.get_height(), obj.get_bg_colour());
    operate_children(obj.get_children(), p, pool, offset);
}


template<class OBJ, class PAINT, typename ...Args> 
void operate_obj(Console::Objects::TBoard& obj, PAINT& p, TPool& pool, QPoint offset)
{
    printf("***paint BOARD %d\n", obj.get_id());

    p.fillRect(offset.x(), offset.y(), obj.get_width(), obj.get_height(), obj.get_bg_colour());
    operate_children(obj.get_children(), p, pool, offset);
}

} // namespace Operations
} // namespace Console

#endif // PAINTER_H
