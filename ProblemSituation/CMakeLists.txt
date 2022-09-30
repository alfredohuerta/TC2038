cmake_minimum_required(VERSION 3.23)
project(ProblemSituation)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(ProblemSituation
        codeAnalysis.h
        main.cpp)
