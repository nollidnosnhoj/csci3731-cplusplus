#include <iostream>
#include <string>
#include "Fish.h"

// Fish's constructor
// Adds the arguments into their appropriate attributes.
// Adds the fish pointer to the population linked list.
Fish::Fish(double speed, int d, int tr) : direction(d), turnRate(tr) {

    this->x = 0.0;
    this->y = 0.0;
    this->speed = speed;
    this->distance = 0.0;
    this->dead = false;
}

// Destructor for when the fish is deleted from the heap. Also will remove itself from the linked list.
Fish::~Fish() {
    
}

void Fish::swim() {

}

// Return whether the fish is dead (distance is more than 100 units).
bool Fish::isDead() const {
    return dead;
}

double Fish::getDistance() const {
    return distance;
}

// Override << operator from the ostream to print fish's information.
std::ostream& operator << (std::ostream& out, const Fish& f) {
    out << "Current Distance: " << f.getDistance() << "\n";
    return out;
}