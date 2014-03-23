/*
Language: C++
IDE: Dev-C++ 5.4.2
Author: Rohan D. Shah

Description:
This class represents the entire world in which the game is contained. It has the status/state of the game after every move.

*/
#ifndef WORLD_H
#define WORLD_H
#include "Grid.h"
#include "Player.h"

class World
{
// create a grid and player object.
// world consists of the grid, the status of the game and player.
Grid *grid;
Player *player;
int time, moves, maxTime; // status of the game

public:
	World() {}
	virtual ~World() { 
	/*if(grid)
	delete grid; */
	delete player; 
	}
	
	// setters
	void setGrid(Grid *grid) { this->grid = grid; }
	void setTime(int time) { this->time = time; }
	void setMaxTime(int maxTime) { this->maxTime = maxTime; }
	void setMoves(int moves) { this->moves = moves; }
	Player *getPlayer() { return player; }
	
	// getters
    void setPlayer(Player *player) { this->player = player; }	
	int getTime() { return	time; }
	int getMaxTime() { return maxTime; }
	int getMoves() { return	moves; }

	Grid *getGrid() { return grid; }
	// Copy constructor
	// for deep copying
/*World(const World& cSource)
{ 
    // m_pchString is a pointer, so we need to deep copy it if it is non-null
    if (cSource.grid)
    {
        // allocate memory for our copy
        grid = new Grid();
        grid=cSource.grid;
        
        player=new Player();
        player=cSource.player;
 
    }
}
// Assignment operator
World& operator=(const World& cSource)
{
    // check for self-assignment
    if (this == &cSource)
        return *this;
 
    // first we need to deallocate any value that this string is holding!
    delete[] grid;
    delete[] player;
 
    
 
    // now we need to deep copy m_pchString
    if (cSource.grid)
    {
        // allocate memory for our copy
 
        // Copy the parameter the newly allocated memory
        grid = new Grid();
        grid=cSource.grid;
        
        player=new Player();
        player=cSource.player;
    } 
    return *this;
}
     virtual ~World() // destructor
    {
        // We need to deallocate our buffer
        delete[] grid;
        delete[] player;
 
    }*/
	void displayWorld() ;
};
#endif // WORLD_H
