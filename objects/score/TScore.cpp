#include "TScore.h"

namespace Console {
namespace Objects {

TScore::TScore(): 
    TObject(),
    children(QList<uint16_t>())
{
}


TScore::TScore(uint16_t id, uint16_t w, uint16_t h, QColor bgc): 
    TObject(TObject::TYPE_SCORE, id, w, h, bgc),
    children(QList<uint16_t>())
{
}


TScore::~TScore()
{
}


void TScore::add_child(uint16_t cid)
{
    children.append(cid);
}


const QList<uint16_t>& TScore::get_children()
{
    return children;
}


} // namespace Objects
} // namespace Console
