#ifndef FISH_H
#define FISH_H
class Angle;

class Fish {
    private:
        Fish* next;
        mutable double x;
        mutable double y;
        int double speed;
        Angle direction;
        Angle turnRate;
    public:
        Fish();
        virtual ~Fish();
        void swim() const;
};

#endif