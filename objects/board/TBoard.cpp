#include "TBoard.h"

namespace Console {
namespace Objects {

TBoard::TBoard(): 
    TObject(),
    children(QVector<QPair<object_id_t, QPoint>>()),
    block_size(0)
{
}


TBoard::TBoard(object_id_t id, uint16_t w, uint16_t h, uint16_t bw, QColor bgc, uint16_t block_size): 
    TObject(TObject::TYPE_BOARD, id, w, h, bw, bgc),
    children(QVector<QPair<object_id_t, QPoint>>()),
    block_size(block_size)
{
}


TBoard::~TBoard()
{
}


void TBoard::add_child(object_id_t cid, QPoint pos)
{
    children.push_back(QPair<object_id_t, QPoint>(cid, pos));
}


const QVector<QPair<object_id_t, QPoint>>& TBoard::get_children()
{
    return children;
}


void TBoard::set_weapon_id(object_id_t w)
{
    weapon_id = w;
}


object_id_t TBoard::get_weapon_id()
{
    return weapon_id;
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
