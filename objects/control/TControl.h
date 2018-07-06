#ifndef TCONTROL_H
#define TCONTROL_H

#include "objects/TObject.h"

#include <QList>

namespace Console {
namespace Objects {

class TControl : public TObject
{
    //Q_OBJECT

public:
    TControl();
    TControl(object_id_t id, uint16_t w, uint16_t h, QColor bgc);
    ~TControl();

    void add_child(object_id_t cid);
    const QList<object_id_t>& get_children();

private:
    //grid
    QList<object_id_t> children;
};

} // namespace Objects
} // namespace Console

#endif // TCONTROL_H
