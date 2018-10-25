#ifndef POPULATION_H
#define POPULATION_H
class Fish;

class Population {
    private:
        Fish* head;
        Fish* tail;
        int count;
    public:
        Population();
        virtual ~Population();
        void add(Fish* newborn);
        void remove(Fish* fish);
        int size() const;
        void print() const;
        // Fish* get(int index);
};

#endif