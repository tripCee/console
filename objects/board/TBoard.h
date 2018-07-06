#ifndef TBOARD_H
#define TBOARD_H

#include "objects/TObject.h"

#include <QList>

namespace Console {
namespace Objects {

class TBoard : public TObject
{
    //Q_OBJECT

public:
    TBoard();
    TBoard(uint16_t id, uint16_t w, uint16_t h, QColor bgc, uint16_t block_size);
    ~TBoard();

    void add_child(uint16_t cid);
    const QList<uint16_t>& get_children();
    void set_block_size(uint16_t bs);
    uint16_t get_block_size();

private:
    //grid
    QList<uint16_t> children;
    uint16_t block_size;
};

} // namespace Objects
} // namespace Console

#endif // TBOARD_H
