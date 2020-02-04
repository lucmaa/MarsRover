//
// Created by luc on 2020/1/9.
//

#include "command.h"
#include "state.h"


void LCommand::execute(State *s) {
    s->left();
}


void RCommand::execute(State *s) {
    s->right();
}


void MCommand::execute(State *s) {
    s->pace();
}
