add_executable(SimpleSandbox SimpleSandbox.cpp)
target_compile_features(SimpleSandbox PRIVATE cxx_std_17)
target_link_libraries(SimpleSandbox PRIVATE SimpleEngine fmt::fmt)
