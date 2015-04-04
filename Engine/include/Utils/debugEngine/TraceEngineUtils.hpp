//
// Created by akum on 28.03.2015.
//

#ifndef _GAME_TRACEENGINEUTILS_HPP_
#define _GAME_TRACEENGINEUTILS_HPP_


#include <iostream>
#include <functional>
#include <chrono>
#include <thread>

using namespace std::chrono;
using namespace std;

long long calkTimeExecute(std::function<void(void)> func);


#endif //_GAME_TRACEENGINEUTILS_HPP_
