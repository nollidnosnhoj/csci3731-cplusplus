#include <iostream>
#include "angle.h"

// Angle constructor
Angle::Angle(int x) {
    // Make sure angle stay between 0 and 360 degrees.
    if (x >= 360) {
        this->degrees = x % 360;
    } else if (x < 0) {
        x = x % 360;
        this->degrees = x + 360;
    } else {
        this->degrees = x;
    }
}

// Angle destructor
Angle::~Angle() {

}

// Get angle's degrees
int Angle::get() const {
    return degrees;
}

// Set angle's degrees
void Angle::set(int x) {
    this->degrees = x;
}

// returns an new angle by adding one angle and another.
// the second argument is a refernece to an angle
// method is constant so it does not modify the object's data
Angle Angle::operator+(const Angle& a) const {
    int newDegrees = degrees + a.get();
    if (newDegrees > 360) {
        return Angle(newDegrees - 360);
    }
    return Angle(newDegrees);
}

// returns the reference of an object that is constant.
// the second argument is a reference of an angle
// we want to modify the data of the angle that is being added
const Angle& Angle::operator+=(const Angle& a) {
    degrees += a.get();
    if (degrees > 360) {
        degrees -= 360;
    }
    return *this;
}

// angle - angle
Angle Angle::operator-(const Angle& a) const {
    int newDegrees = degrees - a.get();
    if (newDegrees < 0) {
        return Angle(newDegrees + 360);
    }
    return Angle(newDegrees);
}

// angle -= angle
const Angle& Angle::operator-=(const Angle& a) {
    degrees -= a.get();
    if (degrees < 0) {
        degrees += 360;
    }
    return *this;
}

// angle * angle
Angle Angle::operator*(const Angle& a) const {
    int newDegrees = degrees * a.get();
    if (newDegrees > 360) {
        return Angle(newDegrees % 360);
    }
    return Angle(newDegrees);
}

// angle *= angle
const Angle& Angle::operator*=(const Angle& a) {
    degrees *= a.get();
    if (degrees > 360) {
        degrees = degrees % 360;
    }
    return *this;
}

// angle / angle
Angle Angle::operator/(const Angle& a) const {
    if (a.get() == 0) {
        return Angle(degrees);
    }
    return Angle(degrees / a.get());
}

// angle /= angle
const Angle& Angle::operator/=(const Angle& a) {
    if (a.get() != 0) {
        degrees /= a.get();
    }
    return *this;
}

// angle == angle
bool Angle::operator==(const Angle& a) const {
    return degrees == a.get();
}

// angle = angle
const Angle& Angle::operator=(const Angle& a) {
    this->degrees = a.get();
    return *this;
}

const Angle& Angle::operator=(double x) {
    this->degrees = (int)x;
    return *this;
}

// print object
std::ostream& operator<<(std::ostream& out, const Angle& a) {
    out << "Angle: " << a.get();
    return out;
}