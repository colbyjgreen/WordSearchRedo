cmake_minimum_required(VERSION 4.0)
project(WordSearchRedo)

set(CMAKE_CXX_STANDARD 20)

add_executable(WordSearchRedo main.cpp
        Placement.cpp
        Placement.h
        WordGrid.cpp
        WordGrid.h
        WordSearch.cpp
        WordSearch.h
        Words.h
)
