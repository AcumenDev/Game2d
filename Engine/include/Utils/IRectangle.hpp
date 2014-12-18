#ifndef IRECTANGLE_H
#define IRECTANGLE_H


#include "FPoint.hpp"

class IRectangle {
public:
    IRectangle();
    IRectangle(FPoint leftTop, FPoint rightBottom);
    virtual ~IRectangle();
    FPoint LeftTop;
    FPoint RightBottom;
protected:
private:
};

#endif // IRECTANGLE_H
