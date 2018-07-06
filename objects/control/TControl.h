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
    TControl(uint16_t id, uint16_t w, uint16_t h, QColor bgc);
    ~TControl();

    void add_child(uint16_t cid);
    const QList<uint16_t>& get_children();

private:
    //grid
    QList<uint16_t> children;
};

} // namespace Objects
} // namespace Console

#endif // TCONTROL_H
