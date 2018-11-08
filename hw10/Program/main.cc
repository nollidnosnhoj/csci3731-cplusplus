#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <typeinfo>
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
    for (int i = 0; i < 10; ++i) {
        int speed = rand() % 50 + 1;
        int direction = rand() % 360;
        Fish* fish1 = new FlippyFish(speed, direction, 50);
        population.push_back(fish1);
        Fish* fish2 = new DrunkenFish(speed, direction, 50);
        population.push_back(fish2);
    }

    while (population.size() > 0) {
        for (int i = 0; i < population.size(); ++i) {
            Fish* dead = population[i];
            std::cout << dead << std::endl;
            dead->swim();
            if (dead->isDead()) {
                population.erase(population.begin() + i);
                for (int j = i + 1; j < population.size(); ++i) {
                    population[j - 1] = population[j];
                }
            }
        }
    }
}