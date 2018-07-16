#include "TLeft_button.h"

namespace Console {
namespace Objects {

TLeft_button::TLeft_button(): 
    TObject()
{
}


TLeft_button::TLeft_button(object_id_t id, uint16_t w, uint16_t h, uint16_t bw, QColor bgc, QColor fgc): 
    TObject(TObject::TYPE_CONTROL, id, w, h, bw, bgc),
    foreground_colour(fgc)
{
}


TLeft_button::~TLeft_button()
{
}


QColor TLeft_button::get_foreground_colour()
{
    return foreground_colour;
}


} // namespace Objects
} // namespace Console
