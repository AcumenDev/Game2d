#ifndef SYSTEMSETTINGS_HPP
#define SYSTEMSETTINGS_HPP

#include <iostream>
#include <Utils/fileSystem/FileSystemUtils.hpp>

using std::string;

//TODO ��������� ���������� � cpp
class SystemSettings {
public:
    string get_resFolder() const {
        return _resFolder;
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