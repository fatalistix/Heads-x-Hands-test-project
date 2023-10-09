cmake_minimum_required(VERSION 3.27)
project(Heads_x_Hands_test_project)

set(CMAKE_CXX_STANDARD 17)

add_executable(Heads_x_Hands_test_project main.cpp
        Player.h
        Player.cpp
        Creature.cpp
        Creature.h
        Monster.cpp
        Monster.h
)
