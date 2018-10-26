#ifndef FISH_H
#define FISH_H
#include "Angle.h"
#include <string>

class Fish {
    private:
        mutable double x;   /* x coordinate */
        mutable double y;   /* y coordinate */
        double speed;
        Angle direction;    /* angular direction */
        Angle turnRate;     /* angular turn rate */
        double distance;
    public:
        Fish();                             /* constructor */
        Fish(double speed, int d, int tr);  /* constructor w/ params */
        virtual ~Fish();                    /* destructor */
        void swim();                        /* swim method */
        void setSpeed(double speed);
        void print() const;
        friend std::ostream& operator << (std::ostream& out, const Fish& f);
        Fish* next;
};

#endif