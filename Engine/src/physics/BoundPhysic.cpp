#include "physics/BoundPhysic.hpp"

namespace Physic {
    BoundPhysic::BoundPhysic(std::shared_ptr<b2World> world, int width, int height, FPoint position) {
        b2BodyDef bodyDef;
        float halfWidth = width / 2.0f;
        float halfHeight = height / 2.0f;
        bodyDef.position.Set(
                toPhysicSize(position.x + halfWidth),
                toPhysicSize(position.y + halfHeight));

        _body = world->CreateBody(&bodyDef);
        b2PolygonShape shape;
        shape.SetAsBox(
                toPhysicSize(halfWidth),
                toPhysicSize(halfHeight));
        b2FixtureDef fixtureDef;
        fixtureDef.shape = &shape;

        _body->CreateFixture(&fixtureDef);
    }
}