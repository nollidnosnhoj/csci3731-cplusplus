#ifndef FISH_H
#define FISH_H
#include "Angle.h"

class Fish {
    private:
        mutable double x;   /* x coordinate */
        mutable double y;   /* y coordinate */
        double speed;
        Angle direction;    /* angular direction */
        Angle turnRate;     /* angular turn rate */
    public:
        Fish();             /* constructor */
        virtual ~Fish();    /* destructor */
        Fish* next;
        void swim();  /* swim method */
};

#endif