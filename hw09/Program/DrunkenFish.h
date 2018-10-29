#include "Fish.h"

class DrunkenFish : public Fish {
    public:
        DrunkenFish(double speed, int direction, int turnrate);
        virtual swim() const;
};