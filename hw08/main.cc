#include <string>
#include <iostream>
#include "Fish.h"
#include "Population.h"
#include "Log.h"

int main()
{
    const Log& logging = Log::getInstance();
    logging.LoggingActive(true);
    
    Population p;
    p.add();
    p.add();
    p.print();
    Fish* fish = p.get(1);
    fish->swim();
    p.print();
}