#include "TStorage.h"

namespace Console {
namespace Objects {

TStorage::TStorage(): 
    TObject(),
    children(QList<uint16_t>())
{
}


TStorage::TStorage(object_id_t id, uint16_t w, uint16_t h, QColor bgc): 
    TObject(TObject::TYPE_STORAGE, id, w, h, bgc),
    children(QList<object_id_t>())
{
}


TStorage::~TStorage()
{
}


void TStorage::add_child(object_id_t cid)
{
    children.append(cid);
}


const QList<object_id_t>& TStorage::get_children()
{
    return children;
}


} // namespace Objects
} // namespace Console
