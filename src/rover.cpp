//
// Created by luc on 2020/1/9.
//

#include "rover.h"
#include "state.h"
#include "context.h"

bool Rover::danger_zone[HIGHLAND_HEIGHT][HIGHLAND_WIDTH][4] = { false };

Rover::Rover(int x, int y, char d) {
    s = new NormalState(this);
    p.x = x;
    p.y = y;
    p.d = char2direction(d);
    log = "";
}

Rover::~Rover() {
    if (s) {
        delete s;
        s = nullptr;
    }
}

Direction Rover::char2direction(char d) {
    switch (d) {
        case 'N': return NORTH;
        case 'E': return EAST;
        case 'S': return SOUTH;
        case 'W': return WEST;
        default: return INVALID;
    }
}

void Rover::check_state() {
    if (s->current_state() != STATE::NORMAL_STATE)
        return;

    if (true == danger_zone[p.y][p.x][p.d]) {
        delete s;
        s = new AlertState(this);
        return;
    } else if (p.x > HIGHLAND_WIDTH || p.y > HIGHLAND_HEIGHT || p.x < 0 || p.y < 0) {
        delete s;
        s = new DeadState(this);

        // back to the last position
        if (p.x > HIGHLAND_WIDTH) { p.x = HIGHLAND_WIDTH; }
        if (p.y > HIGHLAND_HEIGHT) { p.y = HIGHLAND_HEIGHT; }
        if (p.x < 0) { p.x = 0; }
        if (p.y < 0) { p.y = 0; }

        if (!danger_zone[p.y][p.x][p.d])
            danger_zone[p.y][p.x][p.d] = true;
    }
}

void Rover::execute(Context &ctx) {
    for (auto const &cmd : ctx.get_command_list()) {
        check_state();

        if (s) {
            s->execute(cmd);
        }
    }
}

int Rover::X() {
    return p.x;
}

int Rover::Y() {
    return p.y;
}

char Rover::D() {
    switch (p.d) {
        case NORTH: return 'N';
        case EAST:  return 'E';
        case SOUTH: return 'S';
        case WEST:  return 'W';
        default: return -1;
    }
}
