#ifndef POPULATION_H
#define POPULATION_H
#include <string>
class Fish;

class Population {
    private:
        Fish* head;                                             /* head pointer */
        int count;                                              /* counter */
        int flipcount;
        int drunkcount;
    public:
        Population();                                           /* constructor */
        virtual ~Population();                                  /* destructor */
        void add(Fish* newborn);
        void remove(Fish* fish);
        int size() const;                                       /* size of population */
        void print() const;                                     /* print populatino */
        Fish* get(int index) const;                             /* return pointer to fish */
};

#endif