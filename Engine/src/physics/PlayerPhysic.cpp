#include "physics/PlayerPhysic.hpp"

namespace Physic {
    PlayerPhysic::PlayerPhysic(std::shared_ptr<b2World> world, float width, float height, FPoint position) {
        b2BodyDef bodyDef;
        bodyDef.type = b2_dynamicBody;
    
        float halfWidth = width / 2.0f;
        float halfHeight = height / 2.0f;

        bodyDef.position.Set(
                toPhysicSize(position.x + halfWidth),
                toPhysicSize(position.y + halfHeight));
        bodyDef.fixedRotation = true;
        b2PolygonShape shape;

        shape.SetAsBox(
                toPhysicSize(halfWidth),
                toPhysicSize(halfHeight));
        _body = world->CreateBody(&bodyDef);
        b2FixtureDef fixtureDef;
        fixtureDef.shape = &shape;
        fixtureDef.friction = 100.0f;
        fixtureDef.restitution = 0.0f;
        fixtureDef.filter.maskBits = 1;

        b2JointDef b2JointDef1;

        _body->CreateFixture(&fixtureDef);
    }

    PlayerPhysic::~PlayerPhysic() {

    }

    void PlayerPhysic::Jump(int jumpSize) {
        _body->SetLinearVelocity(b2Vec2(0, toPhysicSize(-jumpSize)));
    }

    void PlayerPhysic::ToLeft(int stepSize) {
        _body->SetLinearVelocity(b2Vec2(toPhysicSize(-stepSize), 0));
    }

    void PlayerPhysic::ToRight(int stepSize) {
        _body->SetLinearVelocity(b2Vec2(toPhysicSize(stepSize), 0));
    }
}