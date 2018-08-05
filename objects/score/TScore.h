#ifndef TSCORE_H
#define TSCORE_H

#include "objects/TObject.h"

#include <QMap>

namespace Console {
namespace Objects {

class TScore : public TObject
{
    //Q_OBJECT

public:
    TScore();
    TScore(object_id_t id, uint16_t w, uint16_t h, uint16_t bw, QColor bgC);
    ~TScore();

    void add_child(object_id_t cid, QPoint pos);
    const QMap<object_id_t, QPoint>& get_children();
    
private:
    QMap<object_id_t, QPoint> children;
};

} // namespace Objects
} // namespace Console

#endif // TSCORE_H
