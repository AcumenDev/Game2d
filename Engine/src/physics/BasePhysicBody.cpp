#include "physics/BasePhysicBody.hpp"

namespace Physic {
    BasePhysicBody::BasePhysicBody(float physicCoffSize) {
        _physicCoffSize = physicCoffSize;
    }

    BasePhysicBody::~BasePhysicBody() {
        auto world = _body->GetWorld();
        world->DestroyBody(_body);
    }

    FPoint BasePhysicBody::GetPosition() {
        b2AABB aabb;
        b2Fixture *fl = _body->GetFixtureList();
        do {
            if (fl == nullptr) {
                break;
            }
            aabb = fl->GetAABB(0);
        } while (fl = fl->GetNext());
        return FPoint(toScreanSize(aabb.lowerBound.x), toScreanSize(aabb.lowerBound.y));
    }

    void BasePhysicBody::SetUserData(void *data) {
        _body->SetUserData(data);
    }

    float BasePhysicBody::toScreanSize(float i) {
        return i * _physicCoffSize;
    }

    float BasePhysicBody::toPhysicSize(float i) {
        return i / _physicCoffSize;
    }
}