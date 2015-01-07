#ifndef COLLISIONDETECTOR_HPP_INCLUDED
#define COLLISIONDETECTOR_HPP_INCLUDED
#include "Box2D/Box2D.h"
#include "gameObjects/Player.hpp"

namespace Physic {
    class CollisionDetector : public b2ContactListener {
    public:
        CollisionDetector();
        virtual  ~CollisionDetector();

        virtual void BeginContact(b2Contact *contact) override;
    };
}
#endif