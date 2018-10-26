#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Fish.h"
#include "Population.h"
#include "Log.h"

int main()
{
    const Log& logging = Log::getInstance();
    logging.LoggingActive(true);
    
    /* Population p;
    srand(time(NULL));
    p.add(rand() % 10 + 1, rand() % 360, rand() % 360);
    p.print();
    Fish* f = p.get(0);
    f->swim();
    std::cout << *f << std::endl;
    f->swim();
    std::cout << *f << std::endl;
    f->swim();
    std::cout << *f << std::endl;
    f->swim();
    std::cout << *f << std::endl;
    p.remove(f); */

    Population p;
    srand(time(NULL));
    p.add(rand() % 10 + 1, rand() % 360, 90);
    p.add(rand() % 10 + 1, rand() % 360, 90);
    p.add(rand() % 10 + 1, rand() % 360, 90);
    p.add(rand() % 10 + 1, rand() % 360, 90);
    p.add(rand() % 10 + 1, rand() % 360, 90);
    p.add(rand() % 10 + 1, rand() % 360, 90);
    p.add(rand() % 10 + 1, rand() % 360, 90);
    p.add(rand() % 10 + 1, rand() % 360, 90);
    p.add(rand() % 10 + 1, rand() % 360, 90);
    p.add(rand() % 10 + 1, rand() % 360, 90);
    p.add(rand() % 10 + 1, rand() % 360, 90);
    do {
        std::cout << p.size() << std::endl;
        int current = 0;
        while (current < p.size()) {
            Fish* f = p.get(current);
            // std::cout << *f << std::endl;
            f->swim();
            if (f->getDistance() >= 100) {
                p.remove(f);
            }
            ++current;
        }
    } while(p.size() > 0);
}