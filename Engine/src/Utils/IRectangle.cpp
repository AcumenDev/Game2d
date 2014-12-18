#include <Utils/IRectangle.hpp>

IRectangle::IRectangle() {
    //ctor
}

IRectangle::~IRectangle() {
    //dtor
}

IRectangle::IRectangle(FPoint leftTop, FPoint rightBottom) {
    LeftTop = leftTop;
    RightBottom = rightBottom;
}
