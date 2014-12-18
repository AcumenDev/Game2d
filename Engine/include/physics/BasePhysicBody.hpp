#ifndef BASEBODY_HPP_INCLUDED
#define BASEBODY_HPP_INCLUDED
#include <memory>
#include <Box2D/Box2D.h>
#include "Utils/FPoint.hpp"

namespace Physic {
    class BasePhysicBody {
    public:
        BasePhysicBody();
        virtual ~BasePhysicBody();
        virtual FPoint GetPosition();
        virtual void SetUserData(void *data);
    protected:
        b2Body *_body;
    };
}

#endif