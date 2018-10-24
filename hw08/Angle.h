#ifndef ANGLE_H
#define ANGLE_H

class Angle {
    private:
        int degrees;    /* degrees */

    public:
        Angle(int x);   /* constructor */
        virtual ~Angle();   /* destructor */

        int get() const;    /* get degrees method */
        void set(int x);    /* set degrees method (useless) */

        double getSin() const;
        double getCos() const;

        Angle operator+(const Angle& a) const;  /* + operator */    
        const Angle& operator+=(const Angle& a);    /* += operator */
        Angle operator-(const Angle& a) const;  /* - operator */
        const Angle& operator-=(const Angle& a);    /* -= operator */
        Angle operator*(const Angle& a) const;  /* * operator */
        const Angle& operator*=(const Angle& a);    /* *= operator */
        Angle operator/(const Angle& a) const;  /* / operator */
        const Angle& operator/=(const Angle& a);    /* /= operator */
        bool operator==(const Angle& a) const;  /* == operator */
        const Angle& operator=(const Angle& a); /* = operator for angles */
        const Angle& operator=(double x);   /* = operator for doubles */

        friend std::ostream& operator<<(std::ostream& out, const Angle& a);
        // << operator
};

#endif