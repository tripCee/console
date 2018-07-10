#include "TWeapon.h"

namespace Console {
namespace Objects {

TWeapon::TWeapon(): 
    TObject(),
    children(QList<object_id_t>())
{
}


TWeapon::TWeapon(object_id_t id, uint16_t w, uint16_t h, QColor bgc, type_t object_type): 
    TObject(object_type, id, w, h, 0, bgc),
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


void TWeapon::set_ammunition_id(object_id_t id)
{
    ammunition_id = id;
}


object_id_t TWeapon::get_ammunition_id()
{
    return ammunition_id;
}


void TWeapon::set_speed(uint8_t s)
{
    speed = s;
}


uint8_t TWeapon::get_speed()
{
    return speed;
}


void TWeapon::set_max_speed(uint8_t ms)
{
    max_speed = ms;
}


uint8_t TWeapon::get_max_speed()
{
    return max_speed;
}


void TWeapon::set_rotate_speed(uint8_t rs)
{
    rotate_speed = rs;
}


uint8_t TWeapon::get_rotate_speed()
{
    return rotate_speed;
}


void TWeapon::rotate_cw()
{
    direction += rotate_speed;

    if (direction > 360)
    {
        direction -= 360;
    }
}


void TWeapon::rotate_acw()
{
    direction -= rotate_speed;

    if (direction < 0)
    {
        direction += 360;
    }
}


void TWeapon::set_direction(uint16_t d)
{
    direction = d;
}


uint16_t TWeapon::get_direction()
{
    return direction;
}


void TWeapon::set_gun_power(uint8_t gp)
{
    gun_power = gp;
}


uint8_t TWeapon::get_gun_power()
{
    return gun_power;
}


void TWeapon::set_gun_rotate_speed(uint8_t grs)
{
    gun_rotate_speed = grs;
}


uint8_t TWeapon::get_gun_rotate_speed()
{
    return gun_rotate_speed;
}


void TWeapon::rotate_gun_cw()
{
    gun_direction += gun_rotate_speed;

    if (gun_direction > 360)
    {
        gun_direction -= 360;
    }
}


void TWeapon::rotate_gun_acw()
{
    gun_direction -= gun_rotate_speed;

    if (gun_direction < 0)
    {
        gun_direction += 360;
    }
}


void TWeapon::set_gun_direction(uint16_t gd)
{
    gun_direction = gd;
}


uint16_t TWeapon::get_gun_direction()
{
    return gun_direction;
}


} // namespace Objects
} // namespace Console
