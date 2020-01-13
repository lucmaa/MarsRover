//
// Created by luc on 2020/1/9.
//

#include "Rover.h"

Rover::Rover(int x, int y, char d) {
    p.x = x;
    p.y = y;
    p.d = d;
}

Rover::~Rover() {

}

void Rover::turn_left() {
    if ('N' == p.d)
        p.d = 'W';
    else if ('W' == p.d)
        p.d = 'S';
    else if ('S' == p.d)
        p.d = 'E';
    else if ('E' == p.d)
        p.d = 'N';
}

Position Rover::current_pos() {
    return p;
}

void Rover::execute(const std::shared_ptr<Command> &cmd) {
    cmd->execute(*this);
}

void Rover::turn_right() {
    if ('N' == p.d)
        p.d = 'E';
    else if ('E' == p.d)
        p.d = 'S';
    else if ('S' == p.d)
        p.d = 'W';
    else if ('W' == p.d)
        p.d = 'N';
}

void Rover::march() {
    if ('N' == p.d)
        p.y += 1;
    else if ('E' == p.d)
        p.x += 1;
    else if ('S' == p.d)
        p.y -= 1;
    else if ('W' == p.d)
        p.x -= 1;
}
