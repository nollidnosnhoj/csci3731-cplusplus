#ifndef DRUNKENFISH_H
#define DRUNKENFISH_H
#include "Fish.h"

class DrunkenFish : public Fish {
    public:
        DrunkenFish(double speed, int direction, int turnrate);
        virtual void swim() const;  /* overriding swim */
};

#endif