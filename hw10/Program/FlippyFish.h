#ifndef FLIPPYFISH_H
#define FLIPPYFISH_H
#include "Fish.h"

class FlippyFish : public Fish {
    public:
        FlippyFish(double speed, int direction, int turnrate);
        void swim() const;
};

#endif