#include "TBullet.h"

#include <QPainter>

namespace Console {
namespace Objects {

TBullet::TBullet(): 
    TAmmunition()
{
}


TBullet::TBullet(object_id_t id, uint16_t w, uint16_t h, QColor bgc): 
    TAmmunition(id, w, h, bgc, TObject::TYPE_BULLET)
{
}


TBullet::~TBullet()
{
}


QPixmap TBullet::get_sprite()
{
    QPixmap pix(get_width(), get_height());
    pix.fill(Qt::transparent);
    QPainter p(&pix);

    QRect rect(0, 0, get_width(), get_height());

    p.save();
    QPen pen(Qt::transparent);
    pen.setWidth(0);
    p.setPen(pen);
    QBrush brush(get_bg_colour());
    p.setBrush(brush);
    p.drawEllipse(rect);
    p.restore();

    return pix;
}


} // namespace Objects
} // namespace Console
