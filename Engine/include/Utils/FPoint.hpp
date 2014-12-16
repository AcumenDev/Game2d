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

};


#endif // FPOINT_H