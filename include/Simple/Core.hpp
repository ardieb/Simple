//
// Created by Arthur Burke on 2020-01-12.
//

#ifndef SIMPLE_CORE_HPP
#define SIMPLE_CORE_HPP

#ifdef SIMPLE_PLATFORM_WINDOWS
    #ifdef SIMPLE_BUILD_DLL
        #define SIMPLE_API __declspec(dllexport)
    #else
        #define SIMPLE_API __declspec(dllimport)
    #endif
#else
#define SIMPLE_API
#endif

#endif //SIMPLE_CORE_HPP
