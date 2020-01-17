# Note that headers are optional, and do not affect add_library, but they will not
# show up in IDEs unless they are listed in add_library.

# Optionally glob, but only for CMake 3.12 or later:
# file(GLOB HEADER_LIST CONFIGURE_DEPENDS "${ModernCMakeExample_SOURCE_DIR}/include/modern/*.hpp")
set(HEADER_LIST
        # Pre Compiled Header
        "${Simple_SOURCE_DIR}/include/Simple/PCHeader.h"
        # Main App
        "${Simple_SOURCE_DIR}/include/Simple/App.h"
        # Utility Headers
        "${Simple_SOURCE_DIR}/include/Simple/Utility/Log.h"
        "${Simple_SOURCE_DIR}/include/Simple/Utility/MWSRFixedSizeQueue.h"
        "${Simple_SOURCE_DIR}/include/Simple/Utility/CircularBuffer.h"
        # Core headers
        "${Simple_SOURCE_DIR}/include/Simple/Core/Input.h"
        "${Simple_SOURCE_DIR}/include/Simple/Core/KeyCodes.h"
        "${Simple_SOURCE_DIR}/include/Simple/Core/MouseCodes.h"
        # Events
        "${Simple_SOURCE_DIR}/include/Simple/Events/Event.h"
        "${Simple_SOURCE_DIR}/include/Simple/Events/ApplicationEvent.h"
        "${Simple_SOURCE_DIR}/include/Simple/Events/KeyEvent.h"
        "${Simple_SOURCE_DIR}/include/Simple/Events/MouseEvent.h")
set(SOURCE_LIST
        "${Simple_SOURCE_DIR}/src/Core.cpp"
        "${Simple_SOURCE_DIR}/src/App.cpp"
        "${Simple_SOURCE_DIR}/src/Log.cpp"
        "${Simple_SOURCE_DIR}/src/Input.cpp"
        "${Simple_SOURCE_DIR}/src/PCHeader.cpp")

# Make an automatic library - will be static or dynamic based on user setting
add_library(SimpleEngine SHARED ${SOURCE_LIST} ${HEADER_LIST})

# We need this directory, and users of our library will need it too
target_include_directories(SimpleEngine PUBLIC ${Simple_SOURCE_DIR}/include PRIVATE ${Simple_SOURCE_DIR}/include/Simple)
target_include_directories(SimpleEngine PUBLIC ${viennacl_SOURCE_DIR}/viennacl)
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

include("${Simple_SOURCE_DIR}/cmake/PrecompiledHeader.cmake")
add_precompiled_header(SimpleEngine PCHeader.h FORCEINCLUDE)

# IDEs should put the headers in a nice place
source_group(TREE "${PROJECT_SOURCE_DIR}/include" PREFIX "Header Files" FILES ${HEADER_LIST})
