/*
Description:
This is the box class which can be moved, blasted.

Author: Rohan D. Shah
*/
#ifndef BOX_H
#define BOX_H

#include "Actor.h"

// Display symbol for box
const char BOX_SYMBOL = 'B';

class Box : public Actor
{
private:

    /** box location. */
    int row; // x-coordinate
    int col; // y-coordinate

public:
    
    Box() : row(0), col(0), Actor(BOX_SYMBOL) {}
    virtual ~Box() {}

    virtual char getDisplaySymbol() { return BOX_SYMBOL; }

    /**
     * Place box on a grid cell.
     * Returns true if the box could be placed
     * at the desired location.
     */
    bool setLocation(int row, int col, Grid *myGrid, bool flag);


    /**
     * Let the player make a move on box and return true if the box
     * does move, or false if the box cannot move.
     *
     * This box moves in the same direction as the player until it reaches
     * the border of the grid. When it cannot move, the function returns false.
     */
    bool move(int dx, int dy, Grid *myGrid);
};

#endif // BOX_H
