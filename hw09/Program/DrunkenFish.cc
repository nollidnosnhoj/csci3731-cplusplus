#include <cstdlib>
#include <ctime>
#include <math.h>
#include "DrunkenFish.h"

// Use constructor from super class (Fish)
DrunkenFish::DrunkenFish(Population& p, double speed, int direction, int turnrate) : Fish(p, speed, direction, turnrate) { }

// Override swim method
void DrunkenFish::swim() const {
    srand(time(NULL));
    int choice = rand() % 3;

    if (choice == 0) x += speed;
    else if (choice == 1) y += speed;
    else if (choice == 2) x -= speed;
    else y -= speed;

    distance = sqrt(pow(x,2) + pow(y,2));
}