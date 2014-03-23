// A01943549 Rohan D. Shah
#ifndef ACTOR_H
#define ACTOR_H


class Grid;

/**
 * Language: C++
 * IDE: Dev-C++ 5.4.2
 * Author: Rohan D. Shah
 * 
 * Description:
 * Any object or character that can be placed on the grid.
 * It is represented by specific symbols and are placed on the grid
 */
class Actor 
{
protected:
    /** Grid where the actor is located. */
    Grid *grid;
	char symbol;
public:
	
    Actor() {}
    Actor(char actorSymbol) { symbol = actorSymbol; }
    virtual ~Actor() {}

    void setGrid(Grid *grid) { this->grid = grid; }
	void setSymbol(char symbol){ this->symbol = symbol;	}
    /** Return the symbol used to represent this Actor on the grid. */
    virtual char getDisplaySymbol() = 0;
};

#endif // ACTOR_H
