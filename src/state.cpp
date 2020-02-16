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

void State::left()
{
    if (NORTH == r->p.d)
        r->p.d = WEST;
    else if (WEST == r->p.d)
        r->p.d = SOUTH;
    else if (SOUTH == r->p.d)
        r->p.d = EAST;
    else if (EAST == r->p.d)
        r->p.d = NORTH;
}

void State::right()
{
    if (NORTH == r->p.d)
        r->p.d = EAST;
    else if (EAST == r->p.d)
        r->p.d = SOUTH;
    else if (SOUTH == r->p.d)
        r->p.d = WEST;
    else if (WEST == r->p.d)
        r->p.d = NORTH;
}

void State::move()
{
    if (NORTH == r->p.d)
        r->p.y += 1;
    else if (EAST == r->p.d)
        r->p.x += 1;
    else if (SOUTH == r->p.d)
        r->p.y -= 1;
    else if (WEST == r->p.d)
        r->p.x -= 1;
}

void State::message()
{
    r->log = std::to_string(r->X()) + " " + std::to_string(r->Y()) + " " + r->D();
}

DeadState::DeadState(Rover *rover) {
    r = rover;
    s = STATE::DEAD_STATE;
}

void DeadState::message() {
    r->log = std::to_string(r->X()) + " " + std::to_string(r->Y()) + " " + r->D() + " RIP";
}

AlertState::AlertState(Rover *rover) {
    r = rover;
    s = STATE::ALERT_STATE;
}

void AlertState::move()
{
    if (NORTH == r->p.d)
        r->p.y = (r->p.y + 1 > HIGHLAND_HEIGHT ? r->p.y : r->p.y + 1);
    else if (EAST == r->p.d)
        r->p.x = (r->p.x + 1 > HIGHLAND_WIDTH ? r->p.x : r->p.x + 1);
    else if (SOUTH == r->p.d)
        r->p.y = (r->p.y - 1 < 0 ? r->p.y : r->p.y - 1);
    else if (WEST == r->p.d)
        r->p.x = (r->p.x - 1 < 0 ? r->p.x : r->p.x - 1);
}

NormalState::NormalState(Rover *rover)
{
    r = rover;
    s = STATE::NORMAL_STATE;
}

