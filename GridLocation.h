
#ifndef GRIDLOCATION_H
#define GRIDLOCATION_H

#include <cstddef>

class Player;
class Wall;
class Bomb;
class Exit;
class Hostage;
class EmptySpace;
class Box;
class Warp;

const int EMPTY_LOC_SYMBOL = '.';

// Symbol used to represent a location when there is something wrong
const int UNDEFINED_LOC_SYMBOL = '?';

/**
 * Language: C++
 * IDE: Dev-C++ 5.4.2
 * Author: Rohan D. Shah
 * 
 * Description:
 * A cell of the game grid.
 * Each cell can contain a player or a actor piece.
 */
class GridLocation
{
private:
	
	//Actors can be placed on grid location
    Player *player;    
    Wall *wall;
    Bomb *bomb;
    Exit *exitt;
    Hostage *host;
    EmptySpace *emptyspace;
    Box *box;
    Warp *warp;

public:
    GridLocation() : player(NULL), wall(NULL), bomb(NULL), exitt(NULL), host(NULL), box(NULL),warp(NULL), emptyspace(NULL) {}
    virtual ~GridLocation() {};

	// getters and setters
    Player *getPlayer() { return player; }
    void setPlayer(Player *player) { this->player = player; }
    
    Wall *getWall() { return wall; }
    void setWall(Wall *wall) { this->wall = wall; }
    
    Bomb *getBomb() { return bomb; }
    void setBomb(Bomb *bomb) { this->bomb = bomb; }
    
    Exit *getExit() { return exitt; }
    void setExit(Exit *exitt) { this->exitt = exitt; }
    
    Warp *getWarp() { return warp; }
    void setWarp(Warp *warp) { this->warp = warp; }
    
    Hostage *getHost() { return host; }
    void setHost(Hostage *host) { this->host = host; }
    
    EmptySpace *getEmptySpace() { return emptyspace; }
    void setEmptySpace(EmptySpace *emptyspace) { this->emptyspace = emptyspace; }
    
    Box *getBox() { return box; }
    void setBox(Box *box) { this->box = box; }

    bool isEmpty() { return !player && !wall && !bomb && !host && !exitt && !box && !warp; }
	
	// Used when blasting a bomb. returns true if operation carried out succesfully
	bool setNull();

    /** Return the symbol used to represent this location on the grid. */
    char getDisplaySymbol();
};

#endif // GRIDLOCATION_H

