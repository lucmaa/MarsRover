//
// Created by luc on 2020/1/9.
//

#ifndef MARSROVER_ROVER_H
#define MARSROVER_ROVER_H


#include "command.h"
#include "highland.h"
#include "context.h"

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
    friend class State;
    friend class NormalState;
    friend class DeadState;
    friend class AlertState;
public:
    Rover(int x = 0, int y = 0, char d = 'N');
    ~Rover();

    void execute(Context &ctx);
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

inline std::string Rover::logger() {
    return log;
}


#endif //MARSROVER_ROVER_H
