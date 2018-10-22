#ifndef FISH_H
#define FISH_H
class Angle;

class Fish {
    private:
        mutable double x;
        mutable double y;
        double speed;
        mutable Angle& direction;
        Angle& turnRate;
    public:
        Fish();
        virtual ~Fish();
        void swim() const;
};

#endif