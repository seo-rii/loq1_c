cmake_minimum_required(VERSION 3.26)
project(untitled4)

set(CMAKE_CXX_STANDARD 17)


add_library(untitled4 SHARED
        src/block/iblock.cpp
        src/block/block.h src/library.h
        src/block/lblock.cpp
        src/validate/endable.cpp
        src/point.cpp
        src/state.cpp
        src/actions/move.cpp
        src/actions/place.cpp)
