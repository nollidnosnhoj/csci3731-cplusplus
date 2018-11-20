#ifndef FLIPPYFISH_H
#define FLIPPYFISH_H
#include "Fish.h"
#include "Angle.h"

class FlippyFish : public Fish {
    private:
        // direction angle
        Angle<int> direction;
        // turnrate angle
        Angle<int> turnRate;
    public:
        FlippyFish(double speed, int direction, int turnrate);
        virtual void swim();
};

#endif