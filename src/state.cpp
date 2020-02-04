//
// Created by lulu on 2020/2/4.
//

#include "state.h"
#include "rover.h"
#include "command.h"


void State::execute(const std::shared_ptr<Command> &cmd) {
    cmd->execute(this);
}

NormalState::NormalState(Rover *rover) {
    r = rover;
}

void NormalState::left() {
    if ('N' == r->p.d)
        r->p.d = 'W';
    else if ('W' == r->p.d)
        r->p.d = 'S';
    else if ('S' == r->p.d)
        r->p.d = 'E';
    else if ('E' == r->p.d)
        r->p.d = 'N';
}

void NormalState::right() {
    if ('N' == r->p.d)
        r->p.d = 'E';
    else if ('E' == r->p.d)
        r->p.d = 'S';
    else if ('S' == r->p.d)
        r->p.d = 'W';
    else if ('W' == r->p.d)
        r->p.d = 'N';
}

void NormalState::pace() {
    if ('N' == r->p.d)
        r->p.y += 1;
    else if ('E' == r->p.d)
        r->p.x += 1;
    else if ('S' == r->p.d)
        r->p.y -= 1;
    else if ('W' == r->p.d)
        r->p.x -= 1;
}
