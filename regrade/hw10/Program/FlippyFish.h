#ifndef FLIPPYFISH_H
#define FLIPPYFISH_H
#include "Fish.h"
#include "Angle.h"

class FlippyFish : public Fish {
    private:
        Angle<int> direction;                                    /* angular direction */
        Angle<int> turnRate;                                     /* angular turn rate */
    public:
        FlippyFish(double speed, int direction, int turnrate);
        virtual void swim();
};

#endif