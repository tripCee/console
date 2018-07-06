#ifndef TSCORE_H
#define TSCORE_H

#include "objects/TObject.h"

#include <QList>

namespace Console {
namespace Objects {

class TScore : public TObject
{
    //Q_OBJECT

public:
    TScore();
    TScore(object_id_t id, uint16_t w, uint16_t h, QColor bgC);
    ~TScore();

    void add_child(object_id_t cid);
    const QList<object_id_t>& get_children();

private:
    //grid
    QList<object_id_t> children;
};

} // namespace Objects
} // namespace Console

#endif // TSCORE_H
