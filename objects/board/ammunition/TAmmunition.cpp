#include "TAmmunition.h"

#include <math.h> 

#define PI 3.14159265

namespace Console {
namespace Objects {

TAmmunition::TAmmunition(): 
    TObject(),
    pos(0, 0)
{
}


TAmmunition::TAmmunition(object_id_t id, uint16_t w, uint16_t h, QColor bgc, type_t object_type): 
    TObject(object_type, id, w, h, 0, bgc),
    pos(0, 0)
{
}


TAmmunition::~TAmmunition()
{
}


QPointF TAmmunition::get_pos()
{
    return pos;
}


void TAmmunition::set_speed(uint8_t s)
{
    speed = s;
}


uint8_t TAmmunition::get_speed()
{
    return speed;
}


void TAmmunition::set_max_speed(uint8_t ms)
{
    max_speed = ms;
}


uint8_t TAmmunition::get_max_speed()
{
    return max_speed;
}


void TAmmunition::set_power(uint8_t p)
{
    power = p;
}


uint8_t TAmmunition::get_power()
{
    return power;
}


void TAmmunition::set_direction(uint16_t d)
{
    direction = d;
}


uint16_t TAmmunition::get_direction()
{
    return direction;
}


void TAmmunition::set_fired(bool f)
{
    fired = f;
}


bool TAmmunition::get_fired()
{
    return fired;
}


void TAmmunition::update()
{
    if (!fired) return;

    printf("TAmmunition::update\n");
    pos.setX(pos.x() + (speed * cos(direction * PI / 180.0)));
    pos.setY(pos.y() + (speed * sin(direction * PI / 180.0)));

    printf("\t Ammo pos (%f, %f)\n", pos.x(), pos.y());
}


} // namespace Objects
} // namespace Console
