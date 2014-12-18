#ifndef PLAYERPHYSIC_HPP_INCLUDED
#define PLAYERPHYSIC_HPP_INCLUDED
#include <memory>
#include "BasePhysicBody.hpp"
#include "Box2D/Box2D.h"

namespace Physic {
    class PlayerPhysic : public BasePhysicBody {
    public:
        PlayerPhysic(std::shared_ptr<b2World> world, float width, float height, FPoint position);
        ~PlayerPhysic();
    };
}


#endif