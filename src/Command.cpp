//
// Created by luc on 2020/1/9.
//

#include <memory>
#include "Command.h"


void LCommand::execute(Rover &r) {
    r.turn_left();
}


void RCommand::execute(Rover &r) {
    r.turn_right();
}


void MCommand::execute(Rover &r) {
    r.march();
}
