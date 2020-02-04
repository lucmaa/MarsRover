//
// Created by luc on 2020/1/9.
//

#ifndef MARSROVER_ROVER_H
#define MARSROVER_ROVER_H


#include "command.h"

class Command;
class State;

struct Position {
    int x;
    int y;
    char d;
};

class Rover {
    friend class NormalState;
public:
    Rover(int x = 0, int y = 0, char d = 'N');
    ~Rover();

    Position current_pos();
    void transform(State *state);
    void execute(const std::shared_ptr<Command> &cmd);

    int X()  {return p.x;};
    int Y()  {return p.y;};
    char D() {return p.d;};

private:
    Position p;
    State *s;
};

#endif //MARSROVER_ROVER_H
