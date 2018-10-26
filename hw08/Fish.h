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
        bool isDead;
        Angle direction;    /* angular direction */
        Angle turnRate;     /* angular turn rate */ 
    public:
        Fish();                             /* constructor */
        Fish(double speed, int d, int tr);  /* constructor w/ params */
        virtual ~Fish();                    /* destructor */
        void swim();                        /* swim method */
        void print() const;
        double getDistance() const;
        friend std::ostream& operator << (std::ostream& out, const Fish& f);
        Fish* next;
};

#endif