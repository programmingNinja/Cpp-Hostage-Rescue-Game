/**
 * Language: C++
 * IDE: Dev-C++ 5.4.2
 * Author: Rohan D. Shah
 * 
 * Description:
 * An empty space that can be travelled through.
 */
#ifndef EMPTYSPACE_H
#define EMPTYSPACE_H

#include "Actor.h"

// Display symbols for empty space
const char EMPTY_SPACE_SYMBOL = '.';

class EmptySpace : public Actor
{
private:
public:
    EmptySpace() : Actor(EMPTY_SPACE_SYMBOL) {}
    virtual ~EmptySpace() {}

    virtual char getDisplaySymbol() { return EMPTY_SPACE_SYMBOL; }
};

#endif // EMPTYSPACE_H
