#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "Fish.h"
#include "DrunkenFish.h"
#include "FlippyFish.h"
#include "Log.h"
#include "Exception.h"

int main()
{
    // Logging singleton
    const Log& logging = Log::getInstance();
    // Set to active
    logging.LoggingActive(true);
    // Fish collection
    typedef std::vector<Fish*> FishList;
    FishList population;
    srand(time(NULL));
    // fish is born. 5000 fishes are born
    for (int i = 0; i < 2500; ++i) {
        Fish* fish1 = new FlippyFish(rand() % 50 + 1, rand() % 360, 50);
        population.push_back(fish1);
        Fish* fish2 = new DrunkenFish(rand() % 50 + 1);
        population.push_back(fish2);
    }

    std::cout << "Fish is living!" << std::endl;

    // start timer
    clock_t time;
    time = clock();
    // swim until death
    while (population.size() > 0) {
        for (int i = 0; i < population.size(); ++i) {
            Fish* dead = population[i];
            dead->swim();
            if (dead->isDead()) {
                population.erase(population.begin() + i);
                delete(dead);
            }
        }
    }
    time = clock() - time;
    std::cout << "All fishes died in " << ((float) time) / CLOCKS_PER_SEC << " seconds." << std::endl;
}