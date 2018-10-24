#include <string>
#include <iostream>
#include "Angle.h"
#include "Log.h"

int main()
{
    const Log &debug = Log::getInstance();
    debug.LoggingActive(true);
    Angle a1(50);
    std::cout << a1.getSin() << std::endl;
}
