#ifndef FLIPPYFISH_H
#define FLIPPYFISH_H
#include "Fish.h"
class Population;

class FlippyFish : public Fish {
    public:
        FlippyFish(Population& p, double speed, int direction, int turnrate);
};

#endif