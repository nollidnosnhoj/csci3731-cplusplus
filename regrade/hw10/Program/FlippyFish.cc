#include <cstdlib>
#include <ctime>
#include <math.h>
#include "FlippyFish.h"

// Flippy fish constructor
FlippyFish::FlippyFish(double speed, int d, int t)
    : Fish(speed), direction(d), turnRate(t) {
}

// swim pattern for flippy fish
void FlippyFish::swim() {
    // if the fish is alive
    if (!dead) {
        srand(time(NULL));
        int choice = rand() % 3;
        // update direction
        if (choice == 0) direction += turnRate;
        if (choice == 2) direction -= turnRate;
        // update coordinate
        x += speed * direction.getCos();
        y += speed * direction.getSin();
        // update distance
        distance = sqrt(pow(x,2) + pow(y,2));
        // check if the fish is dead
        if (distance >= 100) dead = true;
    }
}