/*
Description:
This class represents each cell on the grid where an actor can be placed. It displays the symbol of the actor
on the cell.
Method:
1)getDisplaySymbol()
Author: Rohan D. Shah
*/
#include <iostream>
#include "GridLocation.h"
#include "Actor.h"
#include "Player.h"
#include "Wall.h"
#include "Bomb.h"
#include "Exit.h"
#include "Player.h"
#include "Hostage.h"
#include "Box.h"
#include "EmptySpace.h"
#include "Warp.h"
using namespace std;

// returns particular symbols of respective actors.
char GridLocation::getDisplaySymbol() {
    if (isEmpty())
        return EMPTY_LOC_SYMBOL;
    else if (player)
        return player->getDisplaySymbol();
    else if (wall)
        return wall->getDisplaySymbol();
    else if (bomb)
        return bomb->getDisplaySymbol();
    else if (host)
        return host->getDisplaySymbol();
    else if (box)
        return box->getDisplaySymbol();
    else if(emptyspace)
    	return emptyspace->getDisplaySymbol();
    else if(exitt)
    	return exitt->getDisplaySymbol();
    else if(warp)
    	return warp->getDisplaySymbol();
    return UNDEFINED_LOC_SYMBOL;
}

// This is used when the bomb blasts the adjacent cell.
// it can blow up only wall and box.
bool GridLocation::setNull()
{
	wall = NULL;
	box = NULL;	
	return true;
}
