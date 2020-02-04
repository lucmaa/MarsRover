//
// Created by luc on 2020/1/9.
//

#ifndef MARSROVER_ROVER_H
#define MARSROVER_ROVER_H


#include "command.h"
#include "highland.h"

class Command;
class State;

enum Direction {
    NORTH = 0,
    EAST,
    SOUTH,
    WEST,
    INVALID
};

typedef struct Position {
    int x;
    int y;
    Direction d;
} Position;

class Rover {
    friend class NormalState;
    friend class DeadState;
public:
    Rover(int x = 0, int y = 0, char d = 'N');
    ~Rover();

    void execute(const std::shared_ptr<Command> &cmd);
    char D();
    std::string logger();
    int X();
    int Y();

private:
    void check_state();
    Direction char2direction(char d);

private:
    static bool danger_zone[HIGHLAND_HEIGHT][HIGHLAND_WIDTH][4];
    Position p;
    State *s;
    std::string log;
};

#endif //MARSROVER_ROVER_H
