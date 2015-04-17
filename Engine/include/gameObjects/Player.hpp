#ifndef PLAYER_H
#define PLAYER_H
#include <memory>
#include "scriptBinding/PlayerScript.hpp"
#include "gameObjects/weapons/WeaponBase.hpp"
#include "GameObjectBase.hpp"
#include "physics/PlayerPhysic.hpp"
#include "ObjectsDrawing/PlayerGraphic.hpp"
#include "render/Camera.hpp"

using namespace Physic;
using namespace Graphic;
using std::shared_ptr;

class Player : public virtual GameObjectBase {
public:
    Player(shared_ptr<PlayerPhysic> physic, shared_ptr<PlayerGraphic> graphic, shared_ptr<PlayerScript> playerScript);
    ~Player();
    void Update(UpdateEventDto updateEventDto) override;
    shared_ptr<ObjectDrawingBase> GetDrawing() const override;
    bool GetIsOnGround() const;
    void SetIsOnGround(bool isOnGround);
    void SetWeapon(shared_ptr<WeaponBase> weapon);

    void SetSceneNone(shared_ptr<SceneNode> sceneNode) override;

private:
    void _updateGraficPosition();
    shared_ptr<PlayerPhysic> _physic;
    shared_ptr<PlayerGraphic> _graphic;
    shared_ptr<PlayerScript> _playerScript;
    bool _isOnGround;
    shared_ptr<Camera> _camera;

    shared_ptr<WeaponBase> _weapon;
    shared_ptr<SceneNode> _sceneNode;
};

#endif // PLAYER_H