#ifndef FISH_H
#define FISH_H
#include <string>
#include "Angle.h"

class Fish {
    protected:
        mutable double x;                                   /* x coordinate */
        mutable double y;                                   /* y coordinate */
        mutable double distance;                            /* distance */
        mutable bool dead;                                  /* is dead ? */
        double speed;                                       /* speed */
        Angle<int> direction;                                    /* angular direction */
        Angle<int> turnRate;                                     /* angular turn rate */
    public:
        Fish(double speed, int d, int tr);                       /* constructor */
        virtual ~Fish();                                                        /* destructor */
        void swim() const;
        bool isDead() const;                                                    /* is dead checker */
        double getDistance() const;
        // friend std::ostream& operator << (std::ostream& out, const Fish& f);    /* << override */                                                           /* reference to next fish */
};

#endif