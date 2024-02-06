cmake_minimum_required(VERSION 3.26)
project(gauntlet)

set(CMAKE_CXX_STANDARD 20)

# RAYLIB ITEMS
set(RAYLIB_DIR "/usr/")
set(RAYLIB_INCLUDE_DIR "${RAYLIB_DIR}/include")
set(RAYLIB_LIBRARY_DIR "${RAYLIB_DIR}/lib64")
set(RAYLIB_LIBRARIES
    "${RAYLIB_LIBRARY_DIR}/libraylib.so"
)
include_directories(${RAYLIB_INCLUDE_DIR} "include")

# Project sources
set(SOURCES
    src/main.cc
)

add_executable(gauntlet ${SOURCES})
target_link_libraries(gauntlet ${RAYLIB_LIBRARIES})

add_executable(pacman src/pacman.cc)
target_link_libraries(pacman ${RAYLIB_LIBRARIES})
