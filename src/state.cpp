//
// Created by lulu on 2020/2/4.
//

#include <iostream>
#include "state.h"
#include "rover.h"
#include "command.h"


void State::execute(const std::shared_ptr<Command> &cmd) {
    cmd->execute(this);
}

DeadState::DeadState(Rover *rover) {
    r = rover;
}

void DeadState::message() {
    r->log = std::to_string(r->X()) + " " + std::to_string(r->Y()) + " " + r->D() + " RIP";
}

SuspendedState::SuspendedState(Rover *rover) {
    r = rover;
}

NormalState::NormalState(Rover *rover) {
    r = rover;
}

void NormalState::left() {
    if (NORTH == r->p.d)
        r->p.d = WEST;
    else if (WEST == r->p.d)
        r->p.d = SOUTH;
    else if (SOUTH == r->p.d)
        r->p.d = EAST;
    else if (EAST == r->p.d)
        r->p.d = NORTH;
}

void NormalState::right() {
    if (NORTH == r->p.d)
        r->p.d = EAST;
    else if (EAST == r->p.d)
        r->p.d = SOUTH;
    else if (SOUTH == r->p.d)
        r->p.d = WEST;
    else if (WEST == r->p.d)
        r->p.d = NORTH;
}

void NormalState::pace() {
    if (NORTH == r->p.d)
        r->p.y += 1;
    else if (EAST == r->p.d)
        r->p.x += 1;
    else if (SOUTH == r->p.d)
        r->p.y -= 1;
    else if (WEST == r->p.d)
        r->p.x -= 1;
}

void NormalState::message() {
    r->log = std::to_string(r->X()) + " " + std::to_string(r->Y()) + " " + r->D();
}
