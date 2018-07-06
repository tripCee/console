#include "TStorage.h"

namespace Console {
namespace Objects {

TStorage::TStorage(): 
    TObject(),
    children(QList<uint16_t>())
{
}


TStorage::TStorage(uint16_t id, uint16_t w, uint16_t h, QColor bgc): 
    TObject(TObject::TYPE_STORAGE, id, w, h, bgc),
    children(QList<uint16_t>())
{
}


TStorage::~TStorage()
{
}


void TStorage::add_child(uint16_t cid)
{
    children.append(cid);
}


const QList<uint16_t>& TStorage::get_children()
{
    return children;
}


} // namespace Objects
} // namespace Console
