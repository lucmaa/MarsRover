//
// Created by lulu on 2020/2/3.
//

#include "Mars.h"

Mars::Mars(const Highland l) {
    land = l;
}

Mars::~Mars() {

}

Rover * Mars::create_rover() {
    return new Rover;
}
