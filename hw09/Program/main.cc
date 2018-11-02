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
#include "Exception.h"

int main()
{
    // Logging singleton
    const Log& logging = Log::getInstance();
    // Set to active
    logging.LoggingActive(true);
    
    // Create population object
    Population p;
    // honestly dont know what this does, but it makes the rand() method work properly
    srand(time(NULL));
    // Counters for both flippy and drunken fishes.
    int flippyCount = 0; 
    int drunkenCount = 0;

    int amount = 0;
    std::cout << "How many fishes (each) do you want in the lake? ";
    std::cin >> amount;
    int turnRate = 0;
    std::cout << "What's the turnrate (in degrees) for each fish? (Input negative integer for random turn rate) ";
    std::cin >> turnRate;
    if (turnRate < 0) {
        turnRate = rand() % 360;
    }

    if (amount > 0) {
        for (int i = 0; i < amount; ++i) {
            Fish* fish1 = new FlippyFish(p, rand() % 50 + 1, rand() % 360, turnRate);
            ++flippyCount;
            Fish* fish2 = new DrunkenFish(p, rand() % 50 + 1, rand() % 360, turnRate);
            ++drunkenCount;
        }
    } else {
        throw Exception("There should be at least 1 fish in the population.");
    }
    
    // Loop until whatever type of fish is gone from the population
    while (flippyCount != 0 && drunkenCount != 0) {
        // Loop through each fish in the population
        for (int i = 0; i < p.size(); ++i) {
            // Grab a fish and make it swim !
            Fish* current = p.get(i);
            current->swim();
            // Check if the fish is dead
            if (current->isDead()) {
                // If the fish is dead, check what kind of fish, and decrement its counter
                const std::type_info& type = typeid(*current);
                if (type == typeid(DrunkenFish)) {
                    --drunkenCount;
                } else {
                    --flippyCount;
                }
                // Remove dead fish from the population.
                delete(current);
            }
        }
    }

    if (flippyCount == 0) std::cout << "There are " << drunkenCount << " drunk fishes left" << std::endl;
    if (drunkenCount == 0) std::cout << "There are " << flippyCount << " flippy fishes left" << std::endl;
}