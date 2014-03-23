/*
Description:
This is the implementation of the box class. It contains method which moves the box when player pushes it, 
places the box on the grid.

Method:
1)setLocation()
2)move()

Author: Rohan D. Shah
*/
#include <iostream>
#include <stdlib.h> 
using namespace std;
#include "World.h"
#include "grid.h"
#include "gridlocation.h"
#include "Box.h"

// setting location of the box.
// flag used for facilitating blasting as well as moving
// if flag is true then the function is called for the purpose of blasting, else for moving
bool Box::setLocation(int row, int col, Grid *myGrid, bool flag) {
    GridLocation *cell = myGrid->getLocation(row, col);

	if(cell->getDisplaySymbol() == '.' || flag)
	{
		if(flag)
		myGrid->getLocation(this->row, this->col)->setBox(NULL); // remove from old location
    	cell->setBox(this);
    	this->row = row;
    	this->col = col;

    	return true;
	}
    
    return false;
    
}

// moving the box in the direction of the player.
bool Box::move(int dx, int dy, Grid *myGrid) {
        // determine new location
        int newRow = row + dx;
        int newCol = col + dy;
		   
        // try to move
        GridLocation *newCell = myGrid->getLocation(newRow, newCol);
        GridLocation *cell = myGrid->getLocation(row, col);
        if (newCell != NULL && newCell->getDisplaySymbol() == '.') {
            cell->setBox(NULL);
			setLocation(newRow, newCol, myGrid, false);
            myGrid->getLocation(newRow, newCol)->setBox(this);
            return true;
        }      
        
    return false;
}

