#include "TControl.h"

namespace Console {
namespace Objects {

TControl::TControl(): 
    TObject(),
    children(QList<uint16_t>())
{
}


TControl::TControl(uint16_t id, uint16_t w, uint16_t h, QColor bgc): 
    TObject(TObject::TYPE_BOARD, id, w, h, bgc),
    children(QList<uint16_t>())
{
}


TControl::~TControl()
{
}


void TControl::add_child(uint16_t cid)
{
    children.append(cid);
}


const QList<uint16_t>& TControl::get_children()
{
    return children;
}


} // namespace Objects
} // namespace Console
