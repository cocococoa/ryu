find_package(Threads REQUIRED)
add_library(ryu STATIC ryu/float.cpp)
target_link_libraries(ryu PRIVATE Threads::Threads)
target_include_directories(ryu PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_features(ryu PUBLIC cxx_std_20)
target_compile_options(ryu PUBLIC -Wall -Wextra)
