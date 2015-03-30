#ifndef POINT_H
#define POINT_H

#include <iostream>
using  std::string;
namespace Utils {
    template<typename T>
    class Point {
    public:
        Point() {
            x = 0;
            y = 0;
        }
        Point(T x, T y) {
            this->x = x;
            this->y = y;
        }
        Point operator*=(T f) {
            x *= f;
            y *= f;
            return *this;
        }

        virtual ~Point() {
        };
        T x, y;

        string toString()
        {
            return "x: "+ std::to_string(x)+" y: "+std::to_string(y);
        }
     };
    typedef Point<float> FPoint;
    typedef Point<int> IPoint;

}
#endif // POINT_H
