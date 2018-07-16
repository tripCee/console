#include "TTurret.h"

#include <QPainter>

namespace Console {
namespace Objects {

TTurret::TTurret(): 
    TWeapon(),
    children(QList<object_id_t>())
{
}


TTurret::TTurret(object_id_t id, uint16_t w, uint16_t h, QColor bgc, QColor sc): 
    TWeapon(id, w, h, bgc, TObject::TYPE_TURRET),
    children(QList<object_id_t>()),
    secondary_colour(sc)
{
}


TTurret::~TTurret()
{
}


QPixmap TTurret::get_sprite()
{
    QPixmap pix(get_width(), get_height());
    pix.fill(Qt::transparent);
    QPainter p(&pix);

    // FIXME: Debug only - add to turret
    int ring_width = int(get_width() * 0.25);
    int gun_height = int(get_width() * 0.6);
    int gun_width = int(get_width() * 0.2);
    QPoint inner_offset(ring_width, ring_width);
    QRect rect(0, 0, get_width(), get_height());
    QRect inner_rect(inner_offset.x(), inner_offset.y(), get_width() - (2 * ring_width), get_width() - (2 * ring_width));
    QRect gun_rect(int(get_width() / 2) - int(gun_width / 2), int(get_width() / 2) - gun_height, gun_width, gun_height);

    p.save();
    QPen outer_pen(Qt::transparent);
    outer_pen.setWidth(0);
    p.setPen(outer_pen);
    QBrush outer_brush(get_bg_colour());
    p.setBrush(outer_brush);
    p.drawEllipse(rect);
    QBrush inner_brush(secondary_colour);
    p.setBrush(inner_brush);
    p.drawEllipse(inner_rect);
    p.drawRect(gun_rect);
    p.restore();

    return pix;
}


void TTurret::add_child(object_id_t cid)
{
    children.append(cid);
}


const QList<uint16_t>& TTurret::get_children()
{
    return children;
}


void TTurret::set_secondary_colour(QColor colour)
{
    secondary_colour = colour;
}


QColor TTurret::get_secondary_colour()
{
    return secondary_colour;
}


} // namespace Objects
} // namespace Console
