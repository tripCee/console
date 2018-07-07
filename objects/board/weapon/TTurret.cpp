#include "TTurret.h"

namespace Console {
namespace Objects {

TTurret::TTurret(): 
    TWeapon(),
    children(QList<object_id_t>())
{
}


TTurret::TTurret(object_id_t id, uint16_t w, uint16_t h, uint16_t bw, QColor bgc): 
    TWeapon(id, w, h, bw, bgc, TObject::TYPE_TURRET),
    children(QList<object_id_t>())
{
}


TTurret::~TTurret()
{
}


void TTurret::add_child(object_id_t cid)
{
    children.append(cid);
}


const QList<uint16_t>& TTurret::get_children()
{
    return children;
}


} // namespace Objects
} // namespace Console
