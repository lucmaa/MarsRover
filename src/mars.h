//
// Created by lulu on 2020/2/3.
//

#ifndef MARSROVER_MARS_H
#define MARSROVER_MARS_H

#include "rover.h"

typedef struct Highland {
    int w;
    int h;
} Highland;

class Mars {
public:
    Mars(const Highland l);
    ~Mars();

private:
    Highland land;
};

#endif //MARSROVER_MARS_H
