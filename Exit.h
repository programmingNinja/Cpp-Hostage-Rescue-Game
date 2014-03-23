
#ifndef EXIT_H
#define EXIT_H

#include "Actor.h"

// Display symbols for exit
const char EXIT_SYMBOL = 'E';


/**
 * Language: C++
 * IDE: Dev-C++ 5.4.2
 * Author: Rohan D. Shah
 * 
 * Description:
 * The exit door which the player can exit from after rescuing every hostage
 */
class Exit : public Actor
{
private:
public:
    Exit() : Actor(EXIT_SYMBOL) {}
    virtual ~Exit() {}

    virtual char getDisplaySymbol() { return EXIT_SYMBOL; }
    
};

#endif // EXIT_H
