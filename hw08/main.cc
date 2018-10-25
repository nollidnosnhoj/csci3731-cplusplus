#include <string>
#include <iostream>
#include "Fish.h"
#include "Population.h"

int main()
{
    Population p;
    Population& pop = p;
    Fish* f1 = new Fish();
    Fish* f2 = new Fish();
    Fish* f3 = new Fish();
    pop.add(f1);
    pop.add(f2);
    pop.add(f3);
    pop.print();
}