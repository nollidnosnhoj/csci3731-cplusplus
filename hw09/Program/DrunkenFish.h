#ifndef DRUNKENFISH_H
#define DRUNKENFISH_H
#include "Fish.h"
class Population;

class DrunkenFish : public Fish {
    public:
        DrunkenFish(Population& p, double speed, int direction, int turnrate);
        virtual void swim() const;  /* overriding swim */
};

#endif