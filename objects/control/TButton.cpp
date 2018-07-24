#include "TButton.h"

namespace Console {
namespace Objects {

TButton::TButton(): 
    TObject()
{
}


TButton::TButton(object_id_t id, 
        uint16_t w, 
        uint16_t h, 
        uint16_t bw, 
        QColor bgc, 
        QColor fgc,
        Qt::Key k,
        object_id_t cid,
        type_t object_type): 
    TObject(object_type, id, w, h, bw, bgc),
    foreground_colour(fgc),
    key(k),
    controlled_id(cid)
{
}


TButton::~TButton()
{
}


QColor TButton::get_foreground_colour()
{
    return foreground_colour;
}


Qt::Key TButton::get_key()
{
    return key;
}


void TButton::set_controlled_id(object_id_t cid)
{
    controlled_id = cid;
}


object_id_t TButton::get_controlled_id()
{
    return controlled_id;
}


} // namespace Objects
} // namespace Console
