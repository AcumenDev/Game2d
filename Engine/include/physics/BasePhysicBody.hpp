#ifndef BASEBODY_HPP_INCLUDED
#define BASEBODY_HPP_INCLUDED
#include <memory>
#include "Utils/IRectangle.hpp"
#include "Utils/IPoint.hpp"
#include <Box2D/Box2D.h>

namespace Physic {
    class BasePhysicBody {
    public:
        BasePhysicBody();
        virtual ~BasePhysicBody();
        virtual IPoint GetPosition();
        virtual void SetUserData(void* data);
    protected:
       // std::shared_ptr<b2World> _world;
        b2Body * _body;
    };
}

#endif