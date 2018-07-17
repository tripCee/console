#ifndef TCONTROL_H
#define TCONTROL_H

#include "objects/TObject.h"

#include <QMap>

namespace Console {
namespace Objects {

class TControl : public TObject
{
    //Q_OBJECT

public:
    TControl();
    TControl(object_id_t id, uint16_t w, uint16_t h, uint16_t bw, QColor bgc);
    ~TControl();

    void add_child(object_id_t cid, QPoint pos);
    const QMap<object_id_t, QPoint>& get_children();

private:
    QMap<object_id_t, QPoint> children;
};

} // namespace Objects
} // namespace Console

#endif // TCONTROL_H
