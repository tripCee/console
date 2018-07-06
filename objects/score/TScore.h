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
    TScore(uint16_t id, uint16_t w, uint16_t h, QColor bgC);
    ~TScore();

    void add_child(uint16_t cid);
    const QList<uint16_t>& get_children();

private:
    //grid
    QList<uint16_t> children;
};

} // namespace Objects
} // namespace Console

#endif // TSCORE_H
