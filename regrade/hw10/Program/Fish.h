#ifndef FISH_H
#define FISH_H
#include <string>
#include "Angle.h"

class Fish {
    protected:
        // x coordinate
        double x;
        // y coordinate
        double y;
        // distance
        double distance;
        // if dead
        bool dead;
        // speed
        double speed;
    public:
        // general fish constructor
        Fish(double speed);
        // destructor
        virtual ~Fish();
        virtual void swim() = 0;
        // get is dead
        bool isDead() const;
        // get distance
        double getDistance() const;
        // << operator
        friend std::ostream& operator << (std::ostream& out, const Fish& f);
};

#endif