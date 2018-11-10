#include <cstdlib>
#include <ctime>
#include <math.h>
#include "FlippyFish.h"

// constructor
FlippyFish::FlippyFish(double speed, int direction, int turnrate) 
    : Fish(speed, direction, turnrate) { }

// swim
void FlippyFish::swim() const{
        srand(time(NULL));
        int choice = rand() % 3;
        if (choice == 0) direction += turnRate;
        if (choice == 2) direction -= turnRate;
        x += speed * direction.getCos();
        y += speed * direction.getSin();
        distance = sqrt(pow(x,2) + pow(y,2));
        if (distance >= 100) dead = true;
}