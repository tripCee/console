#ifndef PAINTER_H
#define PAINTER_H

#include "TPool.h"
#include "objects/All_objects.h"

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


void paint_object_base(Console::Objects::TObject obj, painter& p, QPoint offset, QColor bgc)
{
    uint16_t bw = obj.get_border_width();
    QRect inner_rect(offset.x(), offset.y(), obj.get_width() - bw, obj.get_height() - bw);

    p.save();
    QPen rect_pen(Qt::gray);
    rect_pen.setWidth(bw);
    p.setPen(rect_pen);
    QBrush rect_brush(bgc);
    p.setBrush(rect_brush);
    p.drawRect(inner_rect);
    p.restore();
}


void paint_button_base(Console::Objects::TButton obj, painter& p, QPoint offset)
{
    QColor bgc = obj.get_is_pressed() ? obj.get_foreground_colour() : obj.get_bg_colour();

    paint_object_base(obj, p, offset, bgc);
}

	
template<class OBJ, class PAINT, typename ...Args> 
void operate_obj(OBJ& obj, PAINT& p, TPool& pool, QPoint offset)
{
    Q_UNUSED(obj);
    Q_UNUSED(p);
    Q_UNUSED(pool);
    Q_UNUSED(offset);
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

    // Board (for current level)
    offset += QPoint(score ? score->get_width() : 0, 0);
    auto board = pool.get_object(obj.get_current_board_id());
    if (board) operate(*board, p, pool, offset);

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
    Q_UNUSED(pool);
    printf("***paint SCORE %d %dx%d %d,%d\n", obj.get_id(), obj.get_width(), obj.get_height(), offset.x(), offset.y());

    paint_object_base(obj, p, offset, obj.get_bg_colour());

    //operate_children(obj.get_children(), p, pool, offset);
}


template<class OBJ, class PAINT, typename ...Args> 
void operate_obj(Console::Objects::TBoard& obj, PAINT& p, TPool& pool, QPoint offset)
{
    printf("***paint BOARD %d %dx%d %d,%d\n", obj.get_id(), obj.get_width(), obj.get_height(), offset.x(), offset.y());

    paint_object_base(obj, p, offset, obj.get_bg_colour());

    // Grid
    uint16_t bw = obj.get_border_width();
    QRect inner_rect(offset.x(), offset.y(), obj.get_width() - bw, obj.get_height() - bw);
    p.save();
    QPen grid_pen(QColor(0, 0, 0, 50));
    p.setPen(grid_pen);
    int start_x = inner_rect.x();
    int start_y = inner_rect.y();
    int end_v = start_x + inner_rect.width();
    int end_h = start_y + inner_rect.height();
    int increment = obj.get_block_size() - grid_pen.width();
    int bottom = start_y + inner_rect.height();
    int right = start_x + inner_rect.width();
    for (int i = start_x; i < end_v; i += increment)
    {
        p.drawLine(QPoint(i, offset.y()), QPoint(i, bottom));
    }
    for (int i = start_y; i < end_h; i += increment)
    {
        p.drawLine(QPoint(offset.x(), i), QPoint(right, i));
    }
    p.restore();

    // Weapon
    auto weapon = pool.get_object(obj.get_weapon_id());
    if (weapon) operate(*weapon, p, pool, offset);

    //operate_children(obj.get_children(), p, pool, offset);
}


template<class OBJ, class PAINT, typename ...Args> 
void operate_obj(Console::Objects::TTurret& obj, PAINT& p, TPool& pool, QPoint offset)
{
    Q_UNUSED(pool);
    printf("***paint TURRET %d %dx%d %d,%d\n", obj.get_id(), obj.get_width(), obj.get_height(), offset.x(), offset.y());

    // Do ammo first so it doesn't overlay the weapon
    auto ammo = pool.get_object(obj.get_ammunition_id());
    if (ammo) operate(*ammo, p, pool, offset);

    QPoint turret_pos = offset + QPoint(obj.get_width(), obj.get_width());
    QRect rect(turret_pos.x(), turret_pos.y(), obj.get_width(), obj.get_width());

    QPixmap sprite = obj.get_sprite();

    p.save();
    qreal scale = qMin(sprite.width(), sprite.height()) / qMax(sprite.width(), sprite.height());
    QPointF center(sprite.width() / 2.0, sprite.height() / 2.0); // widget center
    // uncomment to trade performance for quality
    //  painter.setRenderHint(QPainter::SmoothPixmapTransform);
    p.translate(center + turret_pos);
    p.rotate(obj.get_gun_direction());
    p.scale(scale, scale);
    p.drawPixmap(-center, sprite);
    p.restore();
}


template<class OBJ, class PAINT, typename ...Args> 
void operate_obj(Console::Objects::TBullet& obj, PAINT& p, TPool& pool, QPoint offset)
{
    Q_UNUSED(pool);

    if (!obj.get_fired()) return;

    printf("***paint BULLET %d %dx%d %d,%d\n", obj.get_id(), obj.get_width(), obj.get_height(), offset.x(), offset.y());
}


template<class OBJ, class PAINT, typename ...Args> 
void operate_obj(Console::Objects::TControl& obj, PAINT& p, TPool& pool, QPoint offset)
{
    Q_UNUSED(pool);
    printf("***paint CONTROL %d %dx%d %d,%d\n", obj.get_id(), obj.get_width(), obj.get_height(), offset.x(), offset.y());

    paint_object_base(obj, p, offset, obj.get_bg_colour());

    operate_children(obj.get_children(), p, pool, offset);
}


template<class OBJ, class PAINT, typename ...Args> 
void operate_obj(Console::Objects::TLeft_button& obj, PAINT& p, TPool& pool, QPoint offset)
{
    Q_UNUSED(pool);
    printf("***paint LEFT BUTTON %d %dx%d %d,%d\n", obj.get_id(), obj.get_width(), obj.get_height(), offset.x(), offset.y());

    QColor fgc = obj.get_is_pressed() ? obj.get_bg_colour() : obj.get_foreground_colour();
    paint_button_base(obj, p, offset);
}


template<class OBJ, class PAINT, typename ...Args> 
void operate_obj(Console::Objects::TRight_button& obj, PAINT& p, TPool& pool, QPoint offset)
{
    Q_UNUSED(pool);
    printf("***paint RIGHT BUTTON %d %dx%d %d,%d\n", obj.get_id(), obj.get_width(), obj.get_height(), offset.x(), offset.y());

    QColor fgc = obj.get_is_pressed() ? obj.get_bg_colour() : obj.get_foreground_colour();
    paint_button_base(obj, p, offset);
}


template<class OBJ, class PAINT, typename ...Args> 
void operate_obj(Console::Objects::TFire_button& obj, PAINT& p, TPool& pool, QPoint offset)
{
    Q_UNUSED(pool);
    printf("***paint FIRE BUTTON %d %dx%d %d,%d\n", obj.get_id(), obj.get_width(), obj.get_height(), offset.x(), offset.y());

    QColor fgc = obj.get_is_pressed() ? obj.get_bg_colour() : obj.get_foreground_colour();
    paint_button_base(obj, p, offset);
}


template<class OBJ, class PAINT, typename ...Args> 
void operate_obj(Console::Objects::TStorage& obj, PAINT& p, TPool& pool, QPoint offset)
{
    Q_UNUSED(pool);
    printf("***paint STORAGE %d %dx%d %d,%d\n", obj.get_id(), obj.get_width(), obj.get_height(), offset.x(), offset.y());

    paint_object_base(obj, p, offset, obj.get_bg_colour());

    //operate_children(obj.get_children(), p, pool, offset);
}


} // namespace Operations
} // namespace Console

#endif // PAINTER_H
