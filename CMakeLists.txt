cmake_minimum_required(VERSION 3.5)

set(CXX_STANDARD 17)

project(coursework)

option(COURCEWORK_BUILD_TESTS "Build ${PROJECT_NAME} tests" OFF)

file(GLOB_RECURSE ALL_SRC "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
list(REMOVE_ITEM ALL_SRC "${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp")

if(COURCEWORK_BUILD_TESTS)
    add_executable(app ${ALL_SRC})
    target_include_directories(app PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
else()
    list(APPEND ALL_SRC "${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp")

    add_executable(app ${ALL_SRC})
    target_include_directories(app PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
endif()
