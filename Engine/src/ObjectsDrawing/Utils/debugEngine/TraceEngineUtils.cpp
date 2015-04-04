//
// Created by akum on 28.03.2015.
//

#include "Utils/debugEngine/TraceEngineUtils.hpp"

long long calkTimeExecute(std::function<void(void)> func) {
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    func();
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();/// 1000.0f;
}