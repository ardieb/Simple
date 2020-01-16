# Note that headers are optional, and do not affect add_library, but they will not
# show up in IDEs unless they are listed in add_library.

# Optionally glob, but only for CMake 3.12 or later:
# file(GLOB HEADER_LIST CONFIGURE_DEPENDS "${ModernCMakeExample_SOURCE_DIR}/include/modern/*.hpp")
set(HEADER_LIST
        "${Simple_SOURCE_DIR}/include/Simple/SimpleCore.h"
        "${Simple_SOURCE_DIR}/include/Simple/App.h"
        "${Simple_SOURCE_DIR}/include/Simple/Log.h"
        "${Simple_SOURCE_DIR}/include/Simple/MWSRFixedSizeQueue.h"
        "${Simple_SOURCE_DIR}/include/Simple/CircularBuffer.h"
        "${Simple_SOURCE_DIR}/include/Simple/Events/Event.h")
set(SOURCE_LIST
        "${Simple_SOURCE_DIR}/src/Core.cpp"
        "${Simple_SOURCE_DIR}/src/App.cpp"
        "${Simple_SOURCE_DIR}/src/Log.cpp")

# Make an automatic library - will be static or dynamic based on user setting
add_library(SimpleEngine SHARED ${SOURCE_LIST} ${HEADER_LIST})

# We need this directory, and users of our library will need it too
target_include_directories(SimpleEngine PUBLIC ${Simple_SOURCE_DIR}/include PRIVATE ${Simple_SOURCE_DIR}/include/Simple)
target_include_directories(SimpleEngine PUBLIC ${viennacl_SOURCE_DIR}/include)
target_include_directories(SimpleEngine PUBLIC ${spdlog_SOURCE_DIR}/include)
target_include_directories(SimpleEngine PUBLIC ${glfw_SOURCE_DIR}/include)
target_include_directories(SimpleEngine PUBLIC ${fmtlib_SOURCE_DIR}/include)

# This depends on (header only) boost
target_link_libraries(SimpleEngine PRIVATE Boost::boost)
# This depends on viennacl
target_link_libraries(SimpleEngine PRIVATE viennacl)
# This depends on glfw
target_link_libraries(SimpleEngine PRIVATE glfw)
# This depends on spdlog
target_link_libraries(SimpleEngine PRIVATE spdlog)

# All users of this library will need at least C++11
target_compile_features(SimpleEngine PUBLIC cxx_std_17)

configure_file(${Simple_SOURCE_DIR}/include/Cmake.h.in ${Simple_BINARY_DIR}/include/Cmake.h)
target_include_directories(SimpleEngine PUBLIC ${Simple_BINARY_DIR}/include/)

# IDEs should put the headers in a nice place
source_group(TREE "${PROJECT_SOURCE_DIR}/include" PREFIX "Header Files" FILES ${HEADER_LIST})
