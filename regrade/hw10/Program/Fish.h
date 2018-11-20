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
    public:
        Fish(double speed);                       /* constructor */
        virtual ~Fish();                                                        /* destructor */
        virtual void swim() = 0;
        bool isDead() const;                                                    /* is dead checker */
        double getDistance() const;
        friend std::ostream& operator << (std::ostream& out, const Fish& f);    /* << override */                                                           /* reference to next fish */
};

#endif