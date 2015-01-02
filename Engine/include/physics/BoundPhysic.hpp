#ifndef BOUNDPHYSIC_HPP_INCLUDED
#define BOUNDPHYSIC_HPP_INCLUDED


#include "BasePhysicBody.hpp"
#include "Utils/IPoint.hpp"

namespace Physic {
    class BoundPhysic : public BasePhysicBody {

    public:
        BoundPhysic(std::shared_ptr<b2World> world, int height, int width, FPoint position);
    };
}

#endif