#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <math.h>
#include "Fish.h"
#include "Population.h"

// Fish's constructor
// Adds the arguments into their appropriate attributes.
// Adds the fish pointer to the population linked list.
Fish::Fish(double speed, T d, T tr) : direction(d), turnRate(tr), pop(p) {

    this->x = 0.0;
    this->y = 0.0;
    this->speed = speed;
    this->distance = 0.0;
    this->next = NULL;
    this->dead = false;

}

// Destructor for when the fish is deleted from the heap. Also will remove itself from the linked list.
Fish::~Fish() {
    
}

// Return whether the fish is dead (distance is more than 100 units).
bool Fish::isDead() const {
    return dead;
}

// Override << operator from the ostream to print fish's information.
std::ostream& operator << (std::ostream& out, const Fish& f) {
    out << "Current Position: (" << f.x << "," << f.y << ")\n";
    out << "Current Speed: " << f.speed << "\n";
    out << "Current Distance: " << f.distance << "\n";
    return out;
}