#include "SelectableDrawingObject.hpp"

SelectableDrawingObject::SelectableDrawingObject() {
}

SelectableDrawingObject::~SelectableDrawingObject() {
}

bool SelectableDrawingObject::_checkItemSelected(FRectangle rect, FPoint point) {
    auto checkX = point.x >= rect.LeftTop.x;
    auto checkY = point.y >= rect.LeftTop.y;
    auto checkWidth = point.x <= (rect.LeftTop.x + rect.RightBottom.x);
    auto checkHeight = point.y <= (rect.LeftTop.y + rect.RightBottom.y);
    return checkX && checkY && checkWidth && checkHeight;
}
