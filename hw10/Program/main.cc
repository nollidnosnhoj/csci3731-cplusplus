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
    
    std::vector<Fish*> populaiton;
    
}