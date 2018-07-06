#include "TControl.h"

namespace Console {
namespace Objects {

TControl::TControl(): 
    TObject(),
    children(QList<object_id_t>())
{
}


TControl::TControl(object_id_t id, uint16_t w, uint16_t h, QColor bgc): 
    TObject(TObject::TYPE_BOARD, id, w, h, bgc),
    children(QList<object_id_t>())
{
}


TControl::~TControl()
{
}


void TControl::add_child(object_id_t cid)
{
    children.append(cid);
}


const QList<object_id_t>& TControl::get_children()
{
    return children;
}


} // namespace Objects
} // namespace Console