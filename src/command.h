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


class LCommand : public Command {
public:
    void execute(State *s);
};


class RCommand : public Command {
public:
    void execute(State *s);
};


class MCommand : public Command {
public:
    void execute(State *s);
};


class EOC: public Command {
public:
    void execute(State *s);
};


class CommandQueue {
public:
    void execute() {};
};


#endif //MARSROVER_COMMAND_H
