//
// Created by luc on 2020/1/9.
//

#ifndef MARSROVER_COMMAND_H
#define MARSROVER_COMMAND_H


#include <string>
#include <memory>
#include "rover.h"

struct Position;
class Rover;
class State;

class Command {
public:
    virtual ~Command() = default;
    virtual void execute(State *s) = 0;
};


class LeftCommand : public Command {
public:
    void execute(State *s);
};


class RightCommand : public Command {
public:
    void execute(State *s);
};


class MoveCommand : public Command {
public:
    void execute(State *s);
};


class RogerCommand: public Command {
public:
    void execute(State *s);
};



#endif //MARSROVER_COMMAND_H
