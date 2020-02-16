include_directories(${CMAKE_CURRENT_LIST_DIR})
include_directories(../src)

gtest(marsrover
        marsrover.cpp
        ../src/mars.cpp
        ../src/rover.cpp
        ../src/command.cpp
        ../src/state.cpp
        ../src/context.cpp
)
