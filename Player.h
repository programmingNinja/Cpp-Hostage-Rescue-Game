
#ifndef PLAYER_H
#define PLAYER_H
#include "Warp.h"
#include "Actor.h"
class World;
// Display symbol for player
const char PLAYER_SYMBOL = 'P';
/* 
 * Language: C++
 * IDE: Dev-C++ 5.4.2
 * Author: Rohan D. Shah
 * 
 * Description:
 * The player performs various actions like collecting and deploying bombs, rescuing hostages.
 * It has the number of moves taken and time remaining.
 */
class Player : public Actor
{
private:

    /** Player location. */
    int row; // x-coordinate
    int col; // y-coordinate
    
    int bombCollectedValue, maxBomb;
    int hostRescued, hostRemain; 
	Warp warps[10];
public:
    
    Player() : row(0), col(0), maxBomb(3){}
    virtual ~Player() {}

    virtual char getDisplaySymbol() { return PLAYER_SYMBOL; }

    /**
     * Place player on a grid cell.
     * Returns true if the player could be placed
     * at the desired location.
     */
    bool setLocation(int row, int col);

    /**
     * Collects available bombs at current location.
     * Returns true if something was collected.
     */
    bool collectBomb(int bx, int by);
    
    // getters and setters
	int getBombCollected () { return bombCollectedValue; }
	void setBombCollected(int bombCollectedValue) { this->bombCollectedValue = bombCollectedValue;	}
	
	int getHostRescued () { return hostRescued;	}
	void setHostRescued (int hostRescued) { this->hostRescued = hostRescued; }
	
	int getHostRemain ()  { return hostRemain; }
	void setHostRemain (int hostRemain) { this->hostRemain = hostRemain; }
	
	int getMaxBomb () { return maxBomb;	}
	void setMaxBomb (int maxBomb ) { this->maxBomb = maxBomb; }
	
	int getRow(){ return row; }
	int getCol(){ return col; }
    /**
     * Let the player make a move and return true if the player
     * does move, or false if the player cannot move.
     *
     * This player moves until it reaches
     * the border of the grid. 
     */
    Warp getWarp(int t)  {	return warps[t]; }
    char move(int dx, int dy, Grid *myGrid, World *myWorld);
    
    bool setWarps(Warp *warp)
    {
    	char symbol=warp->getDisplaySymbol();
    	warps[symbol-'0'] = *warp;
    }
};

#endif // PLAYER_H
