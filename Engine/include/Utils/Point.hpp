#ifndef POINT_H
#define POINT_H
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
    };
    typedef Point<float> FPoint;
    typedef Point<int> IPoint;

}
#endif // POINT_H
