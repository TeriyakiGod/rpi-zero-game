cmake_minimum_required(VERSION 3.10)
project(rpi-zero-game)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

add_definitions(-DUSE_DEV_LIB)

include_directories(lib/Config lib/Fonts lib/GUI lib/KO lib/LCD lib/Test)
include_directories(rootfs/usr/local/include)

set(LGPIO_LIBRARY_PATH "${PROJECT_SOURCE_DIR}/rootfs/usr/local/lib")
find_library(LGPIO lgpio PATHS ${LGPIO_LIBRARY_PATH} NO_DEFAULT_PATH)

file(GLOB_RECURSE SOURCES "src/*.c" "src/*.cpp" "lib/*/*.c" "lib/*/*.cpp")

add_executable(rpi-zero-game ${SOURCES})

target_link_libraries(rpi-zero-game ${LGPIO})