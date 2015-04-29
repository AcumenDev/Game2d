#ifndef GAME_BASESCRIPTBINDING_H
#define GAME_BASESCRIPTBINDING_H

#include <exception>
#include <memory>
#include "Script.hpp"
#include "Utils/logger/Logger.hpp"

using std::shared_ptr;
using std::string;
using std::exception;

class BaseScriptBinding {
public:
    BaseScriptBinding(shared_ptr<Script> script, string className);

    template<class T>
    T GetGlobalVar(string name) const {
        LuaRef s = getGlobal(_script->GetLuaState(), name.c_str());
        if (s.isNil()) {
            T defaultValue;
            Logger::Get()->Error(_className, "Not loaded '" + name + "' from lua script, used default value");
            return defaultValue;
        }
        return s.cast<T>();
    }

protected:
    shared_ptr<Script> _script;
    string _className;
};

#endif //GAME_BASESCRIPTBINDING_H
