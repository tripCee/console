#include "TLeft_button.h"

namespace Console {
namespace Objects {

TLeft_button::TLeft_button(): 
    TButton()
{
}


TLeft_button::TLeft_button(object_id_t id, uint16_t w, uint16_t h, uint16_t bw, QColor bgc, QColor fgc, object_id_t cid): 
    TButton(id, w, h, bw, bgc, fgc, Qt::Key_Left, cid, TObject::TYPE_LEFT_BUTTON)
{
}


TLeft_button::~TLeft_button()
{
}


} // namespace Objects
} // namespace Console
