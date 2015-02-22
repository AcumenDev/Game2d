#ifndef BASERESOURCEMANAGER_HPP
#define BASERESOURCEMANAGER_HPP

#include <iostream>

using std::string;

template<typename T>
class BaseResourceManager {
public:
    virtual T getResourse(string name) = 0;
};

#endif // BASERESOURCEMANAGER_HPP