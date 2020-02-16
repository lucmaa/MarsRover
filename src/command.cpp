//
// Created by luc on 2020/1/9.
//

#include "command.h"
#include "state.h"


void LeftCommand::execute(State *s) {
    s->left();
}


void RightCommand::execute(State *s) {
    s->right();
}


void MoveCommand::execute(State *s) {
    s->move();
}


void RogerCommand::execute(State *s) {
    s->message();
}
