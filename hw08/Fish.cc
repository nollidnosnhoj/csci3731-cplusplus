#include <cstdlib>
#include "Fish.h"

Fish::Fish()
    : direction(0), turnRate(0) {
    this->x = 0.0;
    this->y = 0.0;
    this->speed = 5.0;
}

Fish::~Fish() {
    
}

void Fish::swim() {
    int choice = rand() % 3;
    if (choice == 0) {
        direction -= turnRate;
    }
    if (choice == 2) {
        direction -= turnRate;
    }
    x += speed * direction.getCos();
    y += speed * direction.getSin();
}