#include <settings/SystemSettings.hpp>
#include <resourceManagers/SpriteAnimationResourceManager.hpp>

SpriteAnimationResourceManager::SpriteAnimationResourceManager(shared_ptr<Logger> logger, shared_ptr<SystemSettings> systemSettings) {
    _name = "SpriteAnimationResourceManager";
    _logger = logger;
    _systemSettings = systemSettings;
}

shared_ptr<SpriteAnimation> SpriteAnimationResourceManager::getResourse(string name) {
    auto path = _systemSettings->get_resFolder() + name;
    std::ifstream spriteAnimation(path.c_str());
    if (!spriteAnimation.is_open()) {
        _logger->Error(_name, "Couldn't load the spriteAnimaton file : " + path);
        return nullptr;
    }
    std::string jsonString = string((std::istreambuf_iterator<char>(spriteAnimation)), (std::istreambuf_iterator<char>()));

    _logger->Debug(_name, jsonString);

    Document d;
    d.Parse<ParseFlag::kParseDefaultFlags>(jsonString.c_str());


    _logger->Debug(_name, d["resFile"].GetString());
    return nullptr;
}