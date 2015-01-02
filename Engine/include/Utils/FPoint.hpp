#ifndef FPOINT_H
#define FPOINT_H

class FPoint {
public:
    FPoint() {
    }
    FPoint(float x, float y) : x(x), y(y) {
    }
    virtual ~FPoint() {
    }
    float x;
    float y;

    FPoint operator*=(float f) {
        x *= f;
        y *= f;
        return *this;
    }
};
#endif // FPOINT_H