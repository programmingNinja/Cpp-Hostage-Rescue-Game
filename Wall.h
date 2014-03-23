
#ifndef WALL_H
#define WALL_H

#include "Actor.h"


// Display symbol for wall
const char WALL_SYMBOL = 'X';

/**
 * Language: C++
 * IDE: Dev-C++ 5.4.2
 * Author: Rohan D. Shah
 * 
 * Description:
 * Wall obstructs the movement of a player. It can be blasted by a bomb
 */
class Wall : public Actor
{
private:
public:
    Wall() : Actor(WALL_SYMBOL) {}
    virtual ~Wall() {}
    
    virtual char getDisplaySymbol() { return WALL_SYMBOL; }

};

#endif // WALL_H
