#ifndef TSTORAGE_H
#define TSTORAGE_H

#include "objects/TObject.h"

#include <QList>

namespace Console {
namespace Objects {

class TStorage : public TObject
{
    //Q_OBJECT

public:
    TStorage();
    TStorage(object_id_t id, uint16_t w, uint16_t h, uint16_t bw, QColor bgc);
    ~TStorage();

    void add_child(object_id_t cid);
    const QList<object_id_t>& get_children();

private:
    //grid
    QList<object_id_t> children;
};

} // namespace Objects
} // namespace Console

#endif // TSTORAGE_H
