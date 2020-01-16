//
// Created by Arthur Burke on 2020-01-12.
//

#ifndef SIMPLE_SIMPLECORE_H
#define SIMPLE_SIMPLECORE_H

#ifdef SIMPLE_PLATFORM_WINDOWS
    #ifdef SIMPLE_BUILD_DLL
        #define SIMPLE_API __declspec(dllexport)
    #else
        #define SIMPLE_API __declspec(dllimport)
    #endif
#else
#define SIMPLE_API
#endif

#define BIT(x) (1 << x) // Bit mask with 1 shifted to the x position

// Precompiled Headers
#include <vector>
#include <string>
#include <cstdlib>
#include <mutex>
#include <tuple>
#include <cstddef>
#include <utility>
#include <memory>
#include <functional>
#include <Cmake.h>

#endif //SIMPLE_SIMPLECORE_H
