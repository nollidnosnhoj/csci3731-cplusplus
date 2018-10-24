#ifndef POPOULATION_H
#define POPOULATION_H
class Fish;

class Population {
    private:
        Fish* head;
        Fish* tail;
        int count;
    public:
        void add() const;
        void remove(Fish*& dead) const;
        int size() const;
        Fish* get(int index) const;
};

#endif