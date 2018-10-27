#ifndef FISH_H
#define FISH_H
#include "Angle.h"
#include <string>

class Fish {
    private:
        mutable double x;   /* x coordinate */
        mutable double y;   /* y coordinate */
        double speed;
        double distance;
        Angle direction;    /* angular direction */
        Angle turnRate;     /* angular turn rate */ 
    public:
        Fish();                             /* constructor */
        Fish(double speed, int d, int tr);  /* constructor w/ params */
        virtual ~Fish();                    /* destructor */
        void swim();                        /* swim method */
        double getDistance() const;         /* get distance getter */
        friend std::ostream& operator << (std::ostream& out, const Fish& f);
        Fish* next;                         /* next fish pointer */
};

#endif