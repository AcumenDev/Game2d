#ifndef IPOINT_H
#define IPOINT_H
class IPoint {
public:
    IPoint();
    IPoint(int x, int y);
    virtual ~IPoint();
    int x;
    int y;
protected:
private:

};
#endif // IPOINT_H