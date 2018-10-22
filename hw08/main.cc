#include <string>
#include "Log.h"

int main()
{
    const Log &debug = Log::getInstance();
    debug.LoggingActive(true);
    debug.print("testing");
    debug.print("Yeeet!");
}
