#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <math.h>
#include "Fish.h"

// constructore with no arguments
Fish::Fish() : direction(0), turnRate(0) {
    this->x = 0.0;
    this->y = 0.0;
    this->speed = 1.0;
    this->distance = 0.0;
    this->next = NULL;
}

// constructor with speed, direction, and turnrate arguments
Fish::Fish(double speed, int d, int tr)
    : direction(d), turnRate(tr) {
    this->x = 0.0;
    this->y = 0.0;
    this->speed = speed;
    this->distance = 0.0;
    this->next = NULL;
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