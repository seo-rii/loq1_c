cmake_minimum_required(VERSION 3.26)
project(loq_v1)

set(CMAKE_CXX_STANDARD 17)


add_library(loq_v1 SHARED
        src/block/block.cpp
        src/block/block.h
	src/library.cpp
	src/library.h
        src/point.cpp
        src/state.cpp
        src/actions/move.cpp
        src/actions/place.cpp
	src/validate/endable.cpp)
