#ifndef OBJECTBASE_H
#define OBJECTBASE_H
#include <string>

class ObjectBase{
public:
    ObjectBase(const std::string &_name) : _nameObject(_name) {
    }
public:
    const std::string & GetNameObject() const {
        return _nameObject;
    }
private:
    std::string _nameObject;
};
#endif