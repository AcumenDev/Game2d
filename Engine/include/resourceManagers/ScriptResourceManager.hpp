//
// Created by akum on 08.04.2015.
//

#ifndef GAME_SCRIPTRESOURCEMANAGER_HPP
#define GAME_SCRIPTRESOURCEMANAGER_HPP

#include <memory>

#include "BaseResourceManager.hpp"
#include "scriptBinding/Script.hpp"
#include "settings/SystemSettings.hpp"

using std::shared_ptr;
using std::make_shared;

class ScriptResourceManager : public BaseResourceManager<shared_ptr<Script>> {
public:
    ScriptResourceManager(shared_ptr<SystemSettings> systemSettings);

    shared_ptr<Script> getResourse(string name) override;

private:
    shared_ptr<SystemSettings> _systemSettings;
};

#endif //GAME_SCRIPTRESOURCEMANAGER_HPP

