#include "physics/PlayerPhysic.hpp"

namespace Physic {
    PlayerPhysic::PlayerPhysic(std::shared_ptr<b2World> world, float width, float height, FPoint position) {
        b2BodyDef bodyDef;
        bodyDef.type = b2_dynamicBody;
    
        float halfWidth = width / 2.0f;
        float halfHeight = height / 2.0f;

        bodyDef.position.Set(
                toPhysicSize(position.x +halfWidth),
                toPhysicSize(position.y +halfHeight));
        b2PolygonShape shape;

        shape.SetAsBox(
                toPhysicSize(halfWidth),
                toPhysicSize(halfHeight));
        _body = world->CreateBody(&bodyDef);
        b2FixtureDef fixtureDef;
        fixtureDef.shape = &shape;
        fixtureDef.density = 1.0f;
        fixtureDef.friction = 0.3f;
        _body->CreateFixture(&fixtureDef);
    }

    PlayerPhysic::~PlayerPhysic() {

    }
}