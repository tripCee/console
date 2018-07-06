#include "TObject.h"

namespace Console {
namespace Objects {

TObject::TObject(): 
    //QObject(),
    id(0),
    width(0),
    height(0),
    bg_colour()
{
}


TObject::TObject(type_t object_type, object_id_t id, uint16_t w, uint16_t h, QColor bgc): 
    //QObject(),
    type(object_type),
    id(id),
    width(w),
    height(h),
    bg_colour(bgc)
{
    
}


TObject::~TObject()
{
}


TObject::type_t TObject::get_type()
{
    return type;
}


void TObject::set_id(object_id_t id)
{
    id = id;
}


object_id_t TObject::get_id()
{
    return id;
}


void TObject::set_size(uint16_t w, uint16_t h)
{
    width = w;
    height = h;
}


void TObject::set_width(uint16_t w)
{
    width = w;
}


void TObject::set_height(uint16_t h)
{
    height = h;
}


uint16_t TObject::get_width()
{
    return width;
}


uint16_t TObject::get_height()
{
    return height;
}


void TObject::set_bg_colour(QColor bgc)
{
    bg_colour = bgc;
}


QColor TObject::get_bg_colour()
{
    return bg_colour;
}


} // namespace Objects
} // namespace Console
