//
// Created by luc on 2020/1/9.
//

#include <memory>
#include "Command.h"


void Command::bind(Rover *rover) {
    r = std::make_shared<Rover *>(rover);
}


void LCommand::execute() {
    (*r)->turn_left();
}


void RCommand::execute() {
    (*r)->turn_right();
}


void MCommand::execute() {
    (*r)->march();
}
