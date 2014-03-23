
#ifndef HOSTAGE_H
#define HOSTAGE_H

#include "Actor.h"

// Display symbols for different minerals
const char HOSTAGE_SYMBOL = 'H';


/**
 * Language: C++
 * IDE: Dev-C++ 5.4.2
 * Author: Rohan D. Shah
 * 
 * Description:
 * Hostage actor which has to be rescued by the player
 */
class Hostage : public Actor
{
private:
public:
    Hostage() : Actor(HOSTAGE_SYMBOL) {}
    virtual ~Hostage() {}

    virtual char getDisplaySymbol() { return HOSTAGE_SYMBOL; }
};

#endif // HOSTAGE_H
