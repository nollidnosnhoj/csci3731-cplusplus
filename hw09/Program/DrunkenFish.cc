#include <cstdlib>
#include <ctime>
#include <math.h>
#include "DrunkenFish.h"

DrunkenFish::DrunkenFish(double speed, int direction, int turnrate) : Fish(speed, direction, turnrate) { }

void DrunkenFish::swim() const {
    srand(time(NULL));
    int choice = rand() % 3;

    if (choice == 0) x += speed;
    else if (choice == 1) y += speed;
    else if (choice == 2) x -= speed;
    else y -= speed;

    distance = sqrt(pow(x,2) + pow(y,2));
}