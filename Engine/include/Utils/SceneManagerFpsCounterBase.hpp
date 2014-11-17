#ifndef SCENEMANAGERFPSCOUNTERBASE_HPP_INCLUDED
#define SCENEMANAGERFPSCOUNTERBASE_HPP_INCLUDED

class SceneManagerFpsCounterBase {
public:
    SceneManagerFpsCounterBase() {};
    virtual void Update(int fps) = 0;
    ~SceneManagerFpsCounterBase() {};
protected:
private:
};

#endif // SCENEMANAGERFPSCOUNTERBASE_HPP_INCLUDED
