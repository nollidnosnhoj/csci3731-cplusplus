#ifndef ANGLE_H
#define ANGLE_H

class Angle {
    private:
        int degrees;

    public:
        Angle(int x);
        virtual ~Angle();

        int get() const;
        void set(int x);

        Angle operator+(const Angle& a) const;

        const Angle& operator+=(const Angle& a);
        Angle operator-(const Angle& a) const;
        const Angle& operator-=(const Angle& a);
        Angle operator*(const Angle& a) const;
        const Angle& operator*=(const Angle& a);
        Angle operator/(const Angle& a) const;
        const Angle& operator/=(const Angle& a);
        bool operator==(const Angle& a) const;
        const Angle& operator=(const Angle& a);

        void print() const;
};

#endif