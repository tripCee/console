#include "TControl.h"

namespace Console {
namespace Objects {

TControl::TControl(): 
    TObject(),
    children(QMap<object_id_t, QPoint>())
{
}


TControl::TControl(object_id_t id, uint16_t w, uint16_t h, uint16_t bw, QColor bgc): 
    TObject(TObject::TYPE_CONTROL, id, w, h, bw, bgc),
    children(QMap<object_id_t, QPoint>())
{
}


TControl::~TControl()
{
}


void TControl::add_child(object_id_t cid, QPoint pos)
{
    children.insert(cid, pos);
}


const QMap<object_id_t, QPoint>& TControl::get_children()
{
    return children;
}


} // namespace Objects
} // namespace Console
