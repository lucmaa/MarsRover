//
// Created by luc on 2020/1/9.
//

#include "rover.h"
#include "state.h"

Rover::Rover(int x, int y, char d) {
    s = new NormalState(this);
    p.x = x;
    p.y = y;
    p.d = d;
}

Rover::~Rover() {
    if (s)
    {
        delete s;
        s = nullptr;
    }
}

void Rover::transform(State *state) {
    s = state;
}

void Rover::execute(const std::shared_ptr<Command> &cmd) {
    if (s)
    {
        s->execute(cmd);
    }
}

Position Rover::current_pos() {
    return p;
}

