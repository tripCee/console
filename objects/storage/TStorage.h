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
    TStorage(uint16_t id, uint16_t w, uint16_t h, QColor bgc);
    ~TStorage();

    void add_child(uint16_t cid);
    const QList<uint16_t>& get_children();

private:
    //grid
    QList<uint16_t> children;
};

} // namespace Objects
} // namespace Console

#endif // TSTORAGE_H
