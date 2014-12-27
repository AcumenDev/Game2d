#ifndef PLAYER_H
#define PLAYER_H
#include <memory>
#include "GameObjectBase.hpp"
#include "physics/PlayerPhysic.hpp"
#include "ObjectsDrawing/PlayerGraphic.hpp"

using namespace Physic;
using namespace Graphic;
using std::shared_ptr;

class Player : public virtual GameObjectBase {
public:
    Player(shared_ptr<Logger> log, shared_ptr<PlayerPhysic> physic, shared_ptr<PlayerGraphic> graphic);
    ~Player();

    void Update(UpdateEventDto updateEventDto) override;

    shared_ptr<ObjectDrawingBase> GetDrawing() const override;
private:
    shared_ptr<PlayerPhysic> _physic;
    shared_ptr<PlayerGraphic> _graphic;
    shared_ptr<Logger> _log;
};

#endif // PLAYER_H