#ifndef FISH_H
#define FISH_H
#include <string>
#include "Angle.h"
class Population;

class Fish {
    protected:
        mutable double x;                                   /* x coordinate */
        mutable double y;                                   /* y coordinate */
        mutable double distance;                            /* distance */
        mutable bool dead;                                  /* is dead ? */
        double speed;                                       /* speed */
        Angle direction;                                    /* angular direction */
        Angle turnRate;                                     /* angular turn rate */
        Population& pop;                                    /* reference to population */
    public:
        Fish(Population& p, double speed, int d, int tr);                       /* constructor */
        virtual ~Fish();                                                        /* destructor */
        void swim();                                                            /* swim */
        bool isDead() const;                                                    /* is dead checker */
        friend std::ostream& operator << (std::ostream& out, const Fish& f);    /* << override */
        Fish* next;                                                             /* reference to next fish */
};

#endif