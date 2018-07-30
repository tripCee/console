#include "TFire_button.h"

namespace Console {
namespace Objects {

TFire_button::TFire_button(): 
    TButton()
{
}


TFire_button::TFire_button(object_id_t id, uint16_t w, uint16_t h, uint16_t bw, QColor bgc, QColor fgc, object_id_t cid): 
    TButton(id, w, h, bw, bgc, fgc, Qt::Key_Space, cid, TObject::TYPE_FIRE_BUTTON)
{
}


TFire_button::~TFire_button()
{
}


} // namespace Objects
} // namespace Console
