#ifndef FISH_H
#define FISH_H
#include <string>
#include "Angle.h"
class Population;

class Fish {
    protected:
        mutable double x;                                   /* x coordinate */
        mutable double y;                                   /* y coordinate */
        mutable double distance;
        double speed;
        mutable bool dead;
        Angle direction;                                    /* angular direction */
        Angle turnRate;                                     /* angular turn rate */
        Population& pop;
    public:
        Fish(Population& p, double speed, int d, int tr);
        virtual ~Fish(); 
        void swim(); 
        bool isDead() const;
        friend std::ostream& operator << (std::ostream& out, const Fish& f);
        Fish* next; 
};

#endif