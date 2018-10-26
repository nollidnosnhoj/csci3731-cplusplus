#ifndef POPULATION_H
#define POPULATION_H
#include <string>
class Fish;

class Population {
    private:
        Fish* head;
        int count;
    public:
        Population();
        virtual ~Population();
        void add();
        void remove(Fish* fish);
        int size() const;
        void print() const;
        Fish* get(int index) const;
};

#endif