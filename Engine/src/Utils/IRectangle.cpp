#include <Utils/IRectangle.hpp>

IRectangle::IRectangle() {
    //ctor
}

IRectangle::~IRectangle() {
    //dtor
}

IRectangle::IRectangle(IPoint leftTop, IPoint rightBottom) {
    LeftTop = leftTop;
    RightBottom = rightBottom;
}
