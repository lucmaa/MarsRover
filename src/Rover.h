//
// Created by luc on 2020/1/9.
//

#ifndef MARSROVER_ROVER_H
#define MARSROVER_ROVER_H


#include <vector>
#include "Command.h"

class Command;

struct Position {
    int x;
    int y;
    char d;
};

class Rover {
public:
    Rover(int x = 0, int y = 0, char d = 'N');
    ~Rover();

    Position current_pos();
    void accept(std::vector<std::shared_ptr<Command>> &cmd);
    void turn_left();
    void turn_right();
    void march();
    void move();


    int X()  {return p.x;};
    int Y()  {return p.y;};
    char D() {return p.d;};

private:
    Position p;
    std::vector<std::shared_ptr<Command>> commands;
};


#endif //MARSROVER_ROVER_H
