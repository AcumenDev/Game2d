#ifndef BASEBODY_HPP_INCLUDED
#define BASEBODY_HPP_INCLUDED
#include <memory>
#include <Box2D/Box2D.h>
#include "Utils/FPoint.hpp"

namespace Physic {
    class BasePhysicBody {
    public:
        BasePhysicBody(float physicCoffSize = 100.0f);
        virtual ~BasePhysicBody();
        virtual FPoint GetPosition();
        virtual void SetUserData(void *data);
    protected:
        float toScreanSize(float i);
        float toPhysicSize(float i);
        b2Body *_body;
    private:
        float _physicCoffSize;
    };
}

#endif