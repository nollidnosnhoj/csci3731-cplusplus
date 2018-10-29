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

    

    /**
     * Takes in user input for both number of fishes in population,
     * turn rate, and
     * number of steps each fish will take. It will also generate a random
     * speed and direction for each fish.
     * After the simulation, it will display the size of the population.
     * 
     * p.add() will create fish object, while p.remove(fish*) remove fish object
     * from heap.
     * 
     * To Log, add logging.print("string"); somewhere in the code.... replace
     * "string" with a string content.
     * 
     * QUESTION:
     * How to add non-string data (integers) into string data? std::string?
     * 
     */
    /* Population p;
    srand(time(NULL));
    int fishes = 0;
    std::cout << "How many fishes?" << std::endl;
    std::cin >> fishes;
    int steps = 0;
    std::cout << "How many steps each fish takes?" << std::endl;
    std::cin >> steps;
    int tr = 0;
    std::cout << "Turnrate for each fish? (in degrees)" << std::endl;
    std::cin >> tr;
    for (int i = 0; i < fishes; ++i) {
        p.add(rand() % 50 + 1, rand() % 360, tr);
    }
    for (int k = 0; k < steps; ++k) {
        for (int i = 0; i < p.size(); ++i) {
            Fish* fish = p.get(i);
            fish->swim();
            if (fish->getDistance() >= 100) {
                p.remove(fish);
            }
            
        }
    }
    std::cout << "Current Fishes: " << p.size() << std::endl;
    std::cout << "Number of fishes died: " << p.getDeadCount() << std::endl; */
}