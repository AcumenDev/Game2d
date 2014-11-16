#include "IRectangle.hpp"

IRectangle::IRectangle() {
    //ctor
}

IRectangle::~IRectangle() {
    //dtor
}


IRectangle::IRectangle(int x, int y, int w, int h) {
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
}
