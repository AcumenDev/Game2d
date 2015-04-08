#include "resourceManagers/ScriptResourceManager.hpp"

ScriptResourceManager::ScriptResourceManager(shared_ptr<SystemSettings> systemSettings) {
    _systemSettings = systemSettings;
}

shared_ptr<Script> ScriptResourceManager::getResourse(string name) {
    return make_shared<Script>(_systemSettings->GetScriptPath(name));
}