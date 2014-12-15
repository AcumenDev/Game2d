#ifndef OBJECTDRAWINGBASE_H
#define OBJECTDRAWINGBASE_H
#include "Utils/IPoint.hpp"

namespace Graphic {
    class ObjectDrawingBase {
    public:
        ObjectDrawingBase() {
        };
        virtual void SetPosition(const IPoint& iPoint) = 0;
        virtual void Draw() = 0;
        virtual ~ObjectDrawingBase() {
        };
    };
}
#endif