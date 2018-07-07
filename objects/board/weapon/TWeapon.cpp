#include "TWeapon.h"

namespace Console {
namespace Objects {

TWeapon::TWeapon(): 
    TObject(),
    children(QList<object_id_t>())
{
}


TWeapon::TWeapon(object_id_t id, uint16_t w, uint16_t h, uint16_t bw, QColor bgc, type_t object_type): 
    TObject(object_type, id, w, h, bw, bgc),
    children(QList<object_id_t>())
{
}


TWeapon::~TWeapon()
{
}


void TWeapon::add_child(object_id_t cid)
{
    children.append(cid);
}


const QList<uint16_t>& TWeapon::get_children()
{
    return children;
}


} // namespace Objects
} // namespace Console
