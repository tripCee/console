#include "TRight_button.h"

namespace Console {
namespace Objects {

TRight_button::TRight_button(): 
    TButton()
{
}


TRight_button::TRight_button(object_id_t id, uint16_t w, uint16_t h, uint16_t bw, QColor bgc, QColor fgc, object_id_t cid): 
    TButton(id, w, h, bw, bgc, fgc, Qt::Key_Right, cid, TObject::TYPE_RIGHT_BUTTON)
{
}


TRight_button::~TRight_button()
{
}


} // namespace Objects
} // namespace Console
