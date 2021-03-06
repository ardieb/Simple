cmake_minimum_required(VERSION 3.14)
project(Simple
        VERSION 0.1
        DESCRIPTION "A simple game engine with real world physics"
        LANGUAGES CXX)


# Only do these if this is the main project, and not if it is included through add_subdirectory
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    # Optionally set things like CMAKE_CXX_STANDARD, CMAKE_POSITION_INDEPENDENT_CODE here
    set(CMAKE_CXX_STANDARD 17)
    # Let's ensure -std=c++xx instead of -std=g++xx
    set(CMAKE_CXX_EXTENSIONS OFF)

    # Let's nicely support folders in IDE's
    set_property(GLOBAL PROPERTY USE_FOLDERS ON)

    # Testing only available if this is the main app
    # Note this needs to be done in the main CMakeLists
    # since it calls enable_testing, which must be in the
    # main CMakeLists.
    include(CTest)

    # Docs only available if this is the main app
    find_package(Doxygen)
    if(Doxygen_FOUND)
        add_subdirectory(docs)
    else()
        message(STATUS "Doxygen not found, not building docs")
    endif()
endif()

# FetchContent added in CMake 3.11, downloads during the configure step
include(FetchContent)
# FetchContent_MakeAvailable was not added until CMake 3.14
if(${CMAKE_VERSION} VERSION_LESS 3.14)
    include(cmake/FetchContent.cmake)
endif()

find_package(Boost REQUIRED)

# Formatting library
FetchContent_Declare(
        fmtlib
        GIT_REPOSITORY https://github.com/fmtlib/fmt.git
        GIT_TAG        5.3.0
)
FetchContent_MakeAvailable(fmtlib)
# ViennaCL submodule
FetchContent_Declare(
        viennacl
        GIT_REPOSITORY https://github.com/viennacl/viennacl-dev.git
)
set(BUILD_TESTING FALSE)
set(BUILD_EXAMPLES FALSE)
FetchContent_MakeAvailable(viennacl)
# GLFW submodule
FetchContent_Declare(
        glfw
        GIT_REPOSITORY https://github.com/glfw/glfw.git
)
set(GLFW_BUILD_EXAMPLES FALSE)
set(GLFW_BUILD_TESTS FALSE)
set(GLFW_BUILD_DOCS FALSE)
FetchContent_MakeAvailable(glfw)
# Spdlog
FetchContent_Declare(
        spdlog
        GIT_REPOSITORY https://github.com/gabime/spdlog.git
)
FetchContent_MakeAvailable(spdlog)

# The compiled library code is here
add_subdirectory(src)

# The executable code is here
add_subdirectory(apps)

# Testing only available if this is the main app
# Emergency override MODERN_CMAKE_BUILD_TESTING provided as well
if((CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME OR SIMPLE_BUILD_TESTING) AND BUILD_TESTING)
    add_subdirectory(tests)
endif()
