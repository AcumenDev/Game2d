#ifndef SYSTEMSETTINGS_HPP
#define SYSTEMSETTINGS_HPP

#include <iostream>

using std::string;

class SystemSettings {
public:
    string get_resFolder() const {
        return _resFolder;
    }

    void set_resFolder(string resFolder) {
        _resFolder = resFolder;
    }

private:
    string _resFolder;
};

#endif