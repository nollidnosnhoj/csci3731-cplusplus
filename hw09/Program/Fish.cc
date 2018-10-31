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
Fish::Fish(Population& p, double speed, int d, int tr) : direction(d), turnRate(tr), pop(p) {
    this->x = 0.0;
    this->y = 0.0;
    this->speed = speed;
    this->distance = 0.0;
    this->next = NULL;
    this->dead = false;

    pop.add(this);
}

// Destructor for when the fish is deleted from the heap. Also will remove itself from the linked list.
Fish::~Fish() {
    pop.remove(this);
}

// Default swimming method.
void Fish::swim() {
    if (!dead) {
        srand(time(NULL));
        int choice = rand() % 3;
        if (choice == 0) direction += turnRate;
        if (choice == 2) direction -= turnRate;
        x += speed * direction.getCos();
        y += speed * direction.getSin();
        distance = sqrt(pow(x,2) + pow(y,2));
        if (distance >= 100) dead = true;
    }
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