//
// Created by lulu on 2020/2/4.
//

#ifndef MARSROVER_STATE_H
#define MARSROVER_STATE_H

#include <memory>

class Command;
class Rover;

enum class STATE {
    NORMAL_STATE,
    ALERT_STATE,
    DEAD_STATE
};

class State {
public:
    void execute(const std::shared_ptr<Command> &cmd);
    STATE current_state();
    virtual void left();
    virtual void right();
    virtual void move();
    virtual void message();

protected:
    Rover *r;
    STATE s;
};

class DeadState : public State {
public:
    DeadState(Rover *rover);
    void left() {};
    void right() {};
    void move() {};
    void message();
};

class AlertState : public State {
public:
    AlertState(Rover *rover);

    void move();
};

class NormalState : public State {
public:
    NormalState(Rover *rover);
};

inline STATE State::current_state()
{
    return s;
}


#endif //MARSROVER_STATE_H
