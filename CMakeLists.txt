cmake_minimum_required(VERSION 3.12)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(bff CXX)

file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS src/*.cpp)
add_executable(bff ${SRC_FILES})

target_include_directories(bff PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(bff PRIVATE ncurses)
