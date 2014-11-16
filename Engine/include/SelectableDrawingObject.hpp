#ifndef SELECTABLEDRAWINGOBJECT_H
#define SELECTABLEDRAWINGOBJECT_H
#include "Engine.hpp"

class SelectableDrawingObject {
public:
    SelectableDrawingObject();
    virtual ~SelectableDrawingObject();
protected:
    bool _checkItemSelected(IRectangle rect, IPoint point);
private:
};

#endif // SELECTABLEDRAWINGOBJECT_H
