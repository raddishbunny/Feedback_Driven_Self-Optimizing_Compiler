cmake_minimum_required(VERSION 3.10)
project(SelfOptimizingCompiler)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE CPP_SOURCES src/*.cpp)

set(C_SOURCES
    src/backend/profiler_runtime.c
)

add_executable(compiler
    ${CPP_SOURCES}
    ${C_SOURCES}
)
