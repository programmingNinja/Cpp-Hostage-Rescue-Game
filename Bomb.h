// A01943549 Rohan D. Shah
#ifndef BOMB_H
#define BOMB_H

#include "Actor.h"

// Display symbols for bomb
const char BOMB_SYMBOL = 'o';
const char ACTIVE_BOMB_SYMBOL = '@';
/**
 * Language: C++
 * IDE: Dev-C++ 5.4.2
 * Author: Rohan D. Shah
 * 
 * Description:
 * A piece of bomb that can be collected by the player.
 * it can be deployed and blasted.
 */
class Bomb : public Actor
{
private:
	int row;
	int col;
	char symbol;
public:
    Bomb() : Actor(BOMB_SYMBOL),symbol(BOMB_SYMBOL) {}
    virtual ~Bomb() {}
	bool setLocation(int row, int col, Grid *myGrid);
    virtual char getDisplaySymbol() { return symbol; }
    
    // to blast at a cell
    char blast(int row , int col, Grid *myGrid);
    
    // to place on the grid
    bool placeBomb(int row, int col, Grid *myGrid);
    
    void setSymbol(char symbol) { this->symbol = symbol; }
    char getSymbol() { return symbol;  }
};

#endif // BOMB_H
