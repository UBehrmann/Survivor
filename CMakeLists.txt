cmake_minimum_required(VERSION 3.24)
project(Survivor)

set(CMAKE_CXX_STANDARD 20)

add_executable(Survivor main.cpp Robot.cpp Robot.h Terrain.cpp Terrain.h Random.cpp Random.h Survivor.cpp Survivor.h Coordonnee.cpp Coordonnee.h)
