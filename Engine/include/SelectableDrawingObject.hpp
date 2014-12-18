#ifndef SELECTABLEDRAWINGOBJECT_H
#define SELECTABLEDRAWINGOBJECT_H
#include "Utils/FRectangle.hpp"

class SelectableDrawingObject {
public:
    SelectableDrawingObject();
    virtual ~SelectableDrawingObject();
protected:
    bool _checkItemSelected(FRectangle rect, FPoint point);
private:
};

#endif // SELECTABLEDRAWINGOBJECT_H
