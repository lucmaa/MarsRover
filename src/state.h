//
// Created by lulu on 2020/2/4.
//

#ifndef MARSROVER_STATE_H
#define MARSROVER_STATE_H

#include <memory>

class Command;
class Rover;

class State {
public:
    void execute(const std::shared_ptr<Command> &cmd);
    virtual void left() {};
    virtual void right() {};
    virtual void pace() {};
    virtual void message() {};

protected:
    Rover *r;
};

class DeadState : public State {
public:
    DeadState(Rover *rover);
    void message();
};

class SuspendedState : public State {
public:
    SuspendedState(Rover *rover);
};

class NormalState : public State {
public:
    NormalState(Rover *rover);

    void left();
    void right();
    void pace();
};

#endif //MARSROVER_STATE_H
