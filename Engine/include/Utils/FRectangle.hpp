#ifndef FRECTANGLE_H
#define FRECTANGLE_H
#include "FPoint.hpp"

class FRectangle {
public:
    FRectangle();
    FRectangle(FPoint leftTop, FPoint rightBottom);
    virtual ~FRectangle();
    FPoint LeftTop;
    FPoint RightBottom;
protected:
private:
};

#endif // FRECTANGLE_H
