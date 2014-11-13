#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H
#include <iostream>
#include <vector>
#include <memory>
#include "SceneNode.hpp"
class SceneManager {
public:
    SceneManager();
    virtual ~SceneManager();
    std::shared_ptr<SceneNode> AddChildNode(std::string name);
    void Draw();
protected:
private:
    std::vector<std::shared_ptr<SceneNode>> _childNodes;
};

#endif // SCENEMANAGER_H
