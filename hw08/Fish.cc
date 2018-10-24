#include <cstdlib>
#include "Fish.h"

Fish::Fish() {
    this->x = 0.0;
    this->y = 0.0;
    this->speed = 5.0;
    this->next = NULL;
}

void Fish::swim() const {
    int choice = rand() % 3;
    if (choice == 0) direction.get() -= turnRate.get();
    else if (choice == 2) direction.get() += turnRate.get();
    x += speed * direction.getCos();
    y += speed * direction.getSin();
}