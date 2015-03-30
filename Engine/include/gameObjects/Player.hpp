#ifndef PLAYER_H
#define PLAYER_H
#include <memory>
#include "GameObjectBase.hpp"
#include "physics/PlayerPhysic.hpp"
#include "ObjectsDrawing/PlayerGraphic.hpp"
#include "render/Camera.hpp"

using namespace Physic;
using namespace Graphic;
using std::shared_ptr;

class Player : public virtual GameObjectBase {
public:
    Player(shared_ptr<Logger> log, shared_ptr<PlayerPhysic> physic, shared_ptr<PlayerGraphic> graphic);
    ~Player();
    void Update(UpdateEventDto updateEventDto) override;
    shared_ptr<ObjectDrawingBase> GetDrawing() const override;
    bool GetIsOnGround() const;
    void SetIsOnGround(bool isOnGround);
private:
    shared_ptr<PlayerPhysic> _physic;
    shared_ptr<PlayerGraphic> _graphic;
    shared_ptr<Logger> _log;
    bool _isOnGround;
    int _stepSize;
    int _jumpSize;
    shared_ptr<Camera> _camera;
};

#endif // PLAYER_H