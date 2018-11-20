#ifndef ANGLE_H
#define ANGLE_H
#include <ostream>
#define PI 3.14

template<class T> class Angle {
    private:
        mutable T degrees;                      /* degrees */
        mutable double cosine;                  /* cosine */
        mutable double sine;                    /* sine */
        mutable bool haveCosine;                /* have cosine? */
        mutable bool haveSine;                  /* have sine? */

    public:
        // constructor
        Angle(T x) {
            if (x >= 360) {
                do {
                    x -= 360;
                } while (x > 360);
            } else if (x < 0) {
                do {
                    x += 360;
                } while (x < 0);
            }
            this->degrees = x;
            this->cosine = 0.0;
            this->sine = 0.0;
            this->haveCosine = false;
            this->haveSine = false;
        }
        virtual ~Angle() {

        }

        // return degrees of an angle
        T& get() const {
            return degrees;
        }

        // set degrees for angle
        void set(T x) {
            this->degrees = x;
            haveCosine = false;
            haveSine = false;
        }

        // get the sin of the angle
        double getSin() const {
            if (!haveSine) {
                sine = sin(degrees * (PI / 180.0));
                haveSine = true;
            }
            return sine;
        }

        // get the cosine of the angle
        double getCos() const {
            if (!haveCosine) {
                cosine = cos(degrees * (PI / 180.0));
                haveCosine = true;
            }
            return cosine;
        }

        // + operator
        Angle operator+(const Angle& a) const {
            int newDegrees = degrees + a.get();
            if (newDegrees > 360) {
                return Angle(newDegrees - 360);
            }
            return Angle(newDegrees);
        }

        // += operator
        const Angle& operator+=(const Angle& a) {
            degrees += a.get();
            if (degrees > 360) {
                degrees -= 360;
            }
            return *this;
        }

        // - operator
        Angle operator-(const Angle& a) const {
            int newDegrees = degrees - a.get();
            if (newDegrees < 0) {
                return Angle(newDegrees + 360);
            }
            return Angle(newDegrees);
        }

        // -= operator
        Angle& operator-=(const Angle& a) {
            degrees -= a.get();
            if (degrees < 0) {
                degrees += 360;
            }
            return *this;
        }

        // * operator
        Angle operator*(const Angle& a) const {
            int newDegrees = degrees * a.get();
            if (newDegrees > 360) {
                return Angle(newDegrees % 360);
            }
            return Angle(newDegrees);
        }

        // *= operator
        const Angle& operator*=(const Angle& a) {
            degrees *= a.get();
            if (degrees > 360) {
                degrees = degrees % 360;
            }
            return *this;
        }

        // / operator
        Angle operator/(const Angle& a) const {
            if (a.get() == 0) {
                return Angle(degrees);
            }
            return Angle(degrees / a.get());
        }

        // /= operator
        const Angle& operator/=(const Angle& a) {
            if (a.get() != 0) {
                degrees /= a.get();
            }
            return *this;
        } 

        // == operator
        bool operator==(const Angle& a) const {
            return degrees == a.get();
        }

        // = operator
        const Angle& operator=(const Angle& a) {
            this->degrees = a.get();
            return *this;
        }

        // = operator (assign double)
        const Angle& operator=(double x) {
            this->degrees = (int)x;
            return *this;
        }
};

#endif