include_directories(${CMAKE_CURRENT_LIST_DIR})
include_directories(../src)

gtest(marsrover
        marsrover.cpp
        ../src/Mars.cpp
        ../src/Rover.cpp
        ../src/Command.cpp
)
