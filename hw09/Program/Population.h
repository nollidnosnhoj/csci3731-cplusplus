#ifndef POPULATION_H
#define POPULATION_H
#include <string>
class Fish;

class Population {
    private:
        Fish* head;                                             /* head pointer */
        int count;                                              /* counter */
        int deadcount;
    public:
        Population();                                           /* constructor */
        virtual ~Population();                                  /* destructor */
        // add fish into heap and population
        void add(Fish* newborn);
        // remove fish from population and heap
        void remove(Fish* fish);
        int size() const;                                       /* size of population */
        void print() const;                                     /* print populatino */
        Fish* get(int index) const;                             /* return pointer to fish */
        int getDeadCount() const;
};

#endif