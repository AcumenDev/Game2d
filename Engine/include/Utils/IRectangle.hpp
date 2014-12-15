#ifndef IRECTANGLE_H
#define IRECTANGLE_H


#include "IPoint.hpp"

class IRectangle {
public:
    IRectangle();
    IRectangle(IPoint leftTop, IPoint rightBottom);
    virtual ~IRectangle();
    IPoint LeftTop;
    IPoint RightBottom;
protected:
private:
};

#endif // IRECTANGLE_H
