#ifndef SYSTEMSETTINGS_HPP
#define SYSTEMSETTINGS_HPP

#include <iostream>
#include <Utils/fileSystem/FileSystemUtils.hpp>

using std::string;

//TODO Перенести реализация в cpp
class SystemSettings {
public:
    string get_resFolder() const {
        return _resFolder;
    }

    string get_mapPathForLvl(string lvl) const {
        return _resFolder + "map/" + lvl + ".map";
    }

    void set_resFolder(string resFolder) {
        _resFolder = resFolder;
    }

    string GetScriptPath(string name) {
        return FileSystem::Path::Combine(string(_resFolder + "scripts"), name + ".lua");
    }

private:
    string _resFolder;
};

#endif