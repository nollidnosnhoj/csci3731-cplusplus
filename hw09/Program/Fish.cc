#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <math.h>
#include "Fish.h"

// constructor with speed, direction, and turnrate arguments
Fish::Fish(Population& p, double speed, int d, int tr) : direction(d), turnRate(tr), population(p) {
    this->x = 0.0;
    this->y = 0.0;
    this->speed = speed;
    this->distance = 0.0;
    this->next = NULL;

    p.add(this);
}

Fish::~Fish() {
    // add code for when the fish is destroyed in heap.
}

// swimming method
void Fish::swim() {
    srand(time(NULL));
    int choice = rand() % 3;
    if (choice == 0) {
        direction += turnRate;
    }
    if (choice == 2) {
        direction -= turnRate;
    }
    x += speed * direction.getCos();
    y += speed * direction.getSin();
    distance = sqrt(pow(x,2) + pow(y,2));
}

// print fish info
std::ostream& operator << (std::ostream& out, const Fish& f) {
    out << "Current Position: (" << f.x << "," << f.y << ")\n";
    out << "Current Speed: " << f.speed << "\n";
    out << "Current Distance: " << f.distance << "\n";
    return out;
}

// getter for distance
double Fish::getDistance() const {
    return distance;
}