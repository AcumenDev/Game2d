#include "SelectableDrawingObject.hpp"

SelectableDrawingObject::SelectableDrawingObject() {
    //ctor
}

SelectableDrawingObject::~SelectableDrawingObject() {
    //dtor
}

bool SelectableDrawingObject::_checkItemSelected(IRectangle rect, FPoint point) {
    auto checkX = point.x >= rect.LeftTop.x;
    auto checkY = point.y >= rect.LeftTop.y;
    auto checkWidth = point.x <= (rect.LeftTop.x + rect.RightBottom.x);
    auto checkHeight = point.y <= (rect.LeftTop.y + rect.RightBottom.y);
    return checkX && checkY && checkWidth && checkHeight;
}
