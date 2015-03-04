#ifndef SCENENODE_H
#define SCENENODE_H
#include <vector>
#include <memory>
#include <gameObjects/GameObjectBase.hpp>
#include "DrawingObject.hpp"
#include "EventInputSystem.hpp"
#include "ObjectBase.hpp"
#include "ObjectsDrawing/ObjectDrawingBase.hpp"

using std::shared_ptr;
using std::string;
using std::vector;
using namespace Graphic;

class SceneNode{
public:
    SceneNode(string nameNode);
    virtual ~SceneNode();
    void Draw();
    void Update(UpdateEventDto updateEventDto);

    void AttachObject(shared_ptr<DrawingObject> drawingObject);
    void AttachObject(shared_ptr<ObjectDrawingBase> drawingObject);
    void AttachObject(shared_ptr<GameObjectBase> gameObjectBase);
protected:
private:
    string _nameNode;
    vector<shared_ptr<SceneNode>> _childNodes;

    vector<shared_ptr<DrawingObject>> _drawingObjectsOld;
    vector<shared_ptr<GameObjectBase>> _gameObjects;
    vector<shared_ptr<ObjectDrawingBase>> _drawingObjects;
};
#endif // SCENENODE_H
