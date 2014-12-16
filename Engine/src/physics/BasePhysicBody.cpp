#include <Utils/FPoint.hpp>
#include "physics/BasePhysicBody.hpp"

namespace Physic {
    BasePhysicBody::BasePhysicBody() {
    }

    BasePhysicBody::~BasePhysicBody() {
    }

    FPoint BasePhysicBody::GetPosition() {
        b2Vec2 localPoint = _body->GetPosition();
        return FPoint(localPoint.x, localPoint.y);
    }

    void BasePhysicBody::SetUserData(void *data) {
        _body->SetUserData(data);
    }
}