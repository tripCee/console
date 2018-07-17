#include "TStorage.h"

namespace Console {
namespace Objects {

TStorage::TStorage(): 
    TObject(),
    children(QMap<object_id_t, QPoint>())
{
}


TStorage::TStorage(object_id_t id, uint16_t w, uint16_t h, uint16_t bw, QColor bgc): 
    TObject(TObject::TYPE_STORAGE, id, w, h, bw, bgc),
    children(QMap<object_id_t, QPoint>())
{
}


TStorage::~TStorage()
{
}


void TStorage::add_child(object_id_t cid, QPoint pos)
{
    children.insert(cid, pos);
}


const QMap<object_id_t, QPoint>& TStorage::get_children()
{
    return children;
}


} // namespace Objects
} // namespace Console
