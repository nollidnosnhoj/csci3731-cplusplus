#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <typeinfo>
#include "Fish.h"
#include "DrunkenFish.h"
#include "FlippyFish.h"
#include "Population.h"
#include "Log.h"

int main()
{
    const Log& logging = Log::getInstance();
    logging.LoggingActive(true);

    Population p;
    srand(time(NULL));
    int flippyCount = 0;
    int drunkenCount = 0;
    for (int i = 0; i < 100; ++i) {
        Fish* fish1 = new FlippyFish(p, rand() % 50 + 1, rand() % 360, 50);
        ++flippyCount;
        Fish* fish2 = new DrunkenFish(p, rand() % 50 + 1, rand() % 360, 50);
        ++drunkenCount;
    }
    while (flippyCount != 0 && drunkenCount != 0) {
        for (int i = 0; i < p.size(); ++i) {
            Fish* current = p.get(i);
            current->swim();
            if (current->isDead()) {
                const std::type_info& type = typeid(*current);
                if (type == typeid(DrunkenFish)) {
                    --drunkenCount;
                } else {
                    --flippyCount;
                }
                p.remove(current);
            }
        }
    }
    if (flippyCount == 0) {
        std::cout << "There are " << drunkenCount << " drunk fishes left" << std::endl;
    }
    if (drunkenCount == 0) {
        std::cout << "There are " << flippyCount << " flippy fishes left" << std::endl;
    }
}