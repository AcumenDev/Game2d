#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Point.hpp"

namespace Utils {
    template<typename T>
    class Rectangle {
    public:
        Rectangle() {

        }
        Rectangle(T leftTop, T rightBottom) {
            LeftTop = leftTop;
            RightBottom = rightBottom;
        }
        virtual ~Rectangle() {
        }
        T LeftTop, RightBottom;
    };

    typedef Rectangle<FPoint> FRectangle;
}
#endif // RECTANGLE_H
