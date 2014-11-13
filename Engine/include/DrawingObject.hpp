#ifndef DRAWINGOBJECT_H
#define DRAWINGOBJECT_H
class DrawingObject {
public:
    DrawingObject();
    virtual ~DrawingObject();
    virtual void Draw() = 0;
protected:
private:
};
#endif // DRAWINGOBJECT_H
