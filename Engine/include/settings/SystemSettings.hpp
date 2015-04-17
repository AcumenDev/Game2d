#ifndef SYSTEMSETTINGS_HPP
#define SYSTEMSETTINGS_HPP

#include <iostream>
#include <Utils/fileSystem/FileSystemUtils.hpp>

using std::string;

//TODO Перенести реалезацию  в cpp
class SystemSettings {
public:
    string get_resFolder() const {
        return _resFolder;
    }

    string get_mapPathForLvl(string name) const {
        return FileSystem::Path::Combine(string(_resFolder + "maps"), name + ".map");
    }

    void set_resFolder(string resFolder) {
        _resFolder = resFolder;
    }

    string GetScriptPath(string name) {
        return FileSystem::Path::Combine(string(_resFolder + "scripts"), name + ".lua");
    }


    string GetTexturePath(string name) {
        return FileSystem::Path::Combine(string(_resFolder + "textures"), name);
    }

    string GetSpriteAnimationPath(string name) {
        return FileSystem::Path::Combine(string(_resFolder + "textures"), name+ ".json");
    }

private:
    string _resFolder;
};

#endif