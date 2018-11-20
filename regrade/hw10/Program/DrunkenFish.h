#ifndef DRUNKENFISH_H
#define DRUNKENFISH_H
#include "Fish.h"

class DrunkenFish : public Fish {
    public:
        DrunkenFish(double speed);
        virtual void swim();  /* overriding swim */
};

#endif