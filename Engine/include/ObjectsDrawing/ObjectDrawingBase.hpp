#ifndef OBJECTDRAWINGBASE_H
#define OBJECTDRAWINGBASE_H
#include <Utils/FPoint.hpp>

namespace Graphic {
    class ObjectDrawingBase {
    public:
        ObjectDrawingBase() {
        };
        virtual void SetPosition(FPoint const &fPoint) = 0;
        virtual void Draw() = 0;
        virtual ~ObjectDrawingBase() {
        };
    };
}
#endif