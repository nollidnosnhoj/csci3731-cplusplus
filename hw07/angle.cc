#include <iostream>
#include "angle.h"

Angle::Angle(int x) {
    if (x > 360) {
        this->degrees = x % 360;
    }

    if (x < 0) {
        int x = x % 360;
        this->degrees = x + 360;
    }
}

Angle::~Angle() {

}

int Angle::get() const {
    return degrees;
}

void Angle::set(int x) {
    this->degrees = x;
}

Angle Angle::operator+(const Angle& a) const {
    int newDegrees = degrees + a.get();
    if (newDegrees > 360) {
        return Angle(newDegrees - 360);
    }
    return Angle(newDegrees);
}

const Angle& Angle::operator+=(const Angle& a) {
    degrees += a.get();
    if (degrees > 360) {
        degrees -= 360;
    }
    return *this;
}

Angle Angle::operator-(const Angle& a) const {
    int newDegrees = degrees - a.get();
    if (newDegrees < 0) {
        return Angle(newDegrees + 360);
    }
    return Angle(newDegrees);
}

const Angle& Angle::operator-=(const Angle& a) {
    degrees -= a.get();
    if (degrees < 0) {
        degrees += 360;
    }
    return *this;
}

Angle Angle::operator*(const Angle& a) const {
    int newDegrees = degrees * a.get();
    if (newDegrees > 360) {
        return Angle(newDegrees % 360);
    }
    return Angle(newDegrees);
}

const Angle& Angle::operator*=(const Angle& a) {
    degrees *= a.get();
    if (degrees > 360) {
        degrees = degrees % 360;
    }
    return *this;
}

Angle Angle::operator/(const Angle& a) const {
    if (a.get() == 0) {
        return Angle(degrees);
    }
    return Angle(degrees / a.get());
}

const Angle& Angle::operator/=(const Angle& a) {
    if (a.get() != 0) {
        degrees /= a.get();
    }
    return *this;
}

bool Angle::operator==(const Angle& a) const {
    return degrees == a.get();
}

const Angle& Angle::operator=(const Angle& a) {
    this->degrees = a.get();
    return *this;
}

void Angle::print() const {
    std::cout << "Angle is " << degrees << std::endl;
}