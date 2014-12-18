#include <Utils/FRectangle.hpp>

FRectangle::FRectangle() {
}

FRectangle::~FRectangle() {
}

FRectangle::FRectangle(FPoint leftTop, FPoint rightBottom) {
    LeftTop = leftTop;
    RightBottom = rightBottom;
}
