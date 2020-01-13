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
    virtual ~Command() = default;
    virtual void execute(Rover &r) = 0;
};


class LCommand : public Command {
public:
    void execute(Rover &r);
};


class RCommand : public Command {
public:
    void execute(Rover &r);
};


class MCommand : public Command {
public:
    void execute(Rover &r);
};


class CommandQueue {
public:
    void execute() {};
};


#endif //MARSROVER_COMMAND_H
