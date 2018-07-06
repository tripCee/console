#include "TBoard.h"

namespace Console {
namespace Objects {

TBoard::TBoard(): 
    TObject(),
    children(QList<object_id_t>()),
    block_size(0)
{
}


TBoard::TBoard(object_id_t id, uint16_t w, uint16_t h, QColor bgc, uint16_t block_size): 
    TObject(TObject::TYPE_BOARD, id, w, h, bgc),
    children(QList<object_id_t>()),
    block_size(block_size)
{
}


TBoard::~TBoard()
{
}


void TBoard::add_child(object_id_t cid)
{
    children.append(cid);
}


const QList<uint16_t>& TBoard::get_children()
{
    return children;
}


void TBoard::set_block_size(uint16_t bs)
{
    block_size = bs;
}    


uint16_t TBoard::get_block_size()
{
    return block_size;
}


} // namespace Objects
} // namespace Console
