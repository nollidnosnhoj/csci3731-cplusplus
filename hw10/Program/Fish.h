#ifndef FISH_H
#define FISH_H
#include <string>
#include "Angle.h"

class Fish {
    protected:
        double x;                                   /* x coordinate */
        double y;                                   /* y coordinate */
        double distance;                            /* distance */
        bool dead;                                  /* is dead ? */
        double speed;                                       /* speed */
        Angle<int> direction;                                    /* angular direction */
        Angle<int> turnRate;                                     /* angular turn rate */
    public:
        Fish(double speed, int d, int tr);                       /* constructor */
        virtual ~Fish();                                                        /* destructor */
        void swim();
        bool isDead() const;                                                    /* is dead checker */
        double getDistance() const;
        // friend std::ostream& operator << (std::ostream& out, const Fish& f);    /* << override */                                                           /* reference to next fish */
};

#endif