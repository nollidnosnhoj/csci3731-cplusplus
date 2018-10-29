#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
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
    for (int i = 0; i < 100; ++i) {
        Fish* fish1 = new FlippyFish(p, rand() % 50 + 1, rand() % 360, 50);
        Fish* fish2 = new DrunkenFish(p, rand() % 50 + 1, rand() % 360, 50);
    }
    p.print();
}