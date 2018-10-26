#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <math.h>
#include "Fish.h"

Fish::Fish() : direction(0), turnRate(0) {
    this->x = 0.0;
    this->y = 0.0;
    this->speed = 1.0;
    this->distance = 0.0;
    this->isDead = false;
    this->next = NULL;
}

Fish::Fish(double speed, int d, int tr)
    : direction(d), turnRate(tr) {
    this->x = 0.0;
    this->y = 0.0;
    this->speed = speed;
    this->distance = 0.0;
    this->isDead = false;
    this->next = NULL;
}

Fish::~Fish() {
    std::cout << "A fish had died" << std::endl;
}

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
    if (distance >= 100) {
        isDead = true;
    }
}

void Fish::print() const {
    std::cout << "Current Position: (" << x << "," << y << ")" << std::endl;
    std::cout << "Current Speed: " << speed << std::endl;
    std::cout << "Current Distance: " << distance << std::endl;
}

std::ostream& operator << (std::ostream& out, const Fish& f) {
    out << "Current Position: (" << f.x << "," << f.y << ")\n";
    out << "Current Speed: " << f.speed << "\n";
    out << "Current Distance: " << f.distance << "\n";
    return out;
}

double Fish::getDistance() const {
    return distance;
}