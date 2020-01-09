//
// Created by luc on 2020/1/9.
//

#ifndef MARSROVER_COMMAND_H
#define MARSROVER_COMMAND_H


#include <string>
#include <memory>
#include "Rover.h"

struct Position;
class Rover;

class Command {
public:
    void bind(Rover *rover);
    virtual void execute() = 0;

public:
    std::shared_ptr<Rover *> r;
};


class LCommand : public Command {
public:
    void execute();
};


class RCommand : public Command {
public:
    void execute();
};


class MCommand : public Command {
public:
    void execute();
};


class CommandQueue {
public:
    void execute() {};
};


#endif //MARSROVER_COMMAND_H
