/*
Description: Bomb Class
Contains the bomb methods that blasts the adjacent cells, places the location of the bomb, and placing the bomb by the player
It should not destroy an exit or a warp object and if the hostage or player gets bombed, the player loses the game.

Methods: 
1)blast()
2)setLocation()
3)placeBomb()

Author: Rohan D. Shah
Note: the repetition in the code could be improved and the code can be made more less repetitive 
*/
#include <iostream>
using namespace std;
#include "Grid.h"
#include "GridLocation.h"
#include "Bomb.h"
#include "EmptySpace.h"

// function that blast the adjacent cell
// returns 'f' if could not be blast
// return 't' if blast successful
// return 'l' if hostage or player blasted
char Bomb::blast(int row , int col, Grid *myGrid)
{
	EmptySpace *emptyspace = new EmptySpace();
	GridLocation *cell = myGrid->getLocation(row, col);
	cell->setBomb(NULL);
	cell->setEmptySpace(emptyspace);
	// invalid location
    if (cell == NULL)
        return 'f';
     
	// checking the bounds and objects. if the object is a warp or an exit, it should not destroy that    	
    // removing the adjacent cell actors for the blast.
    // removes only wall and boxes
    if(row >= 0 && row < myGrid->getNumRows() && col+1 >= 0 && col+1 < myGrid->getNumCols() &&
	myGrid->getLocation(row, col+1)->getDisplaySymbol() != 'E' && (myGrid->getLocation(row, col+1)->getWarp() == NULL))
    myGrid->getLocation(row, col+1)->setNull();//right
    
    if(row-1 >= 0 && row-1 < myGrid->getNumRows() && col >= 0 && col < myGrid->getNumCols() &&
	myGrid->getLocation(row-1, col)->getDisplaySymbol() != 'E' && (myGrid->getLocation(row-1, col)->getWarp() == NULL))
    myGrid->getLocation(row-1, col)->setNull();//up
    
    if(row >= 0 && row < myGrid->getNumRows() && col-1 >= 0 && col-1 < myGrid->getNumCols() &&
	myGrid->getLocation(row, col-1)->getDisplaySymbol() != 'E' && (myGrid->getLocation(row, col-1)->getWarp() == NULL))
    myGrid->getLocation(row, col-1)->setNull();//left
    
    if(row+1 >= 0 && row+1 < myGrid->getNumRows() && col >= 0 && col < myGrid->getNumCols() &&
	myGrid->getLocation(row+1, col)->getDisplaySymbol() != 'E' && (myGrid->getLocation(row+1, col)->getWarp() == NULL))
    myGrid->getLocation(row+1, col)->setNull();//down
    
    if(row-1 >= 0 && row-1 < myGrid->getNumRows() && col+1 >= 0 && col+1 < myGrid->getNumCols() &&
	myGrid->getLocation(row-1, col+1)->getDisplaySymbol() != 'E' && (myGrid->getLocation(row-1, col+1)->getWarp() == NULL))
    myGrid->getLocation(row-1, col+1)->setNull();//topright corner
    
    if(row-1 >= 0 && row-1 < myGrid->getNumRows() && col-1 >= 0 && col-1 < myGrid->getNumCols() &&
	myGrid->getLocation(row-1, col-1)->getDisplaySymbol() != 'E' && (myGrid->getLocation(row-1, col-1)->getWarp() == NULL))
    myGrid->getLocation(row-1, col-1)->setNull();//topleft corner
    
    if(row+1 >= 0 && row+1 <= myGrid->getNumRows() && col-1 >= 0 && col-1 < myGrid->getNumCols() &&
	myGrid->getLocation(row+1, col-1)->getDisplaySymbol() != 'E' && (myGrid->getLocation(row+1, col-1)->getWarp() == NULL))
    myGrid->getLocation(row+1, col-1)->setNull();//bottomleft corner
    
    if(row+1 >= 0 && row+1 <= myGrid->getNumRows() && col+1 >= 0 && col+1 < myGrid->getNumCols()&&
	myGrid->getLocation(row+1, col+1)->getDisplaySymbol() != 'E' && (myGrid->getLocation(row+1, col+1)->getWarp() == NULL))
    myGrid->getLocation(row+1, col+1)->setNull();//bottomright corner
    
    
    if(myGrid->getLocation(row, col+1)->getDisplaySymbol() != 'P' && 
	   myGrid->getLocation(row, col+1)->getDisplaySymbol() != 'H' &&
	   row >= 0 && row < myGrid->getNumRows() && col+1 >= 0 && col+1 < myGrid->getNumCols())
    {
    	// condition for recursive blasting, if there is a bomb in the vicinity, it will blast too
    	if(myGrid->getLocation(row, col+1)->getDisplaySymbol() == 'o')
    	{
    		blast(row, col+1, myGrid);
    	}
    	if(myGrid->getLocation(row, col+1)->getDisplaySymbol() != 'E' && (myGrid->getLocation(row, col+1)->getWarp() == NULL) )
		myGrid->getLocation(row, col+1)->setEmptySpace(emptyspace);//right
	}
    else if(myGrid->getLocation(row, col+1)->getDisplaySymbol() != 'P' && 
	   myGrid->getLocation(row, col+1)->getDisplaySymbol() != 'H')
    return 'l';
    else
    return 't';
    
	if(myGrid->getLocation(row-1, col)->getDisplaySymbol() != 'P' && 
	   myGrid->getLocation(row-1, col)->getDisplaySymbol() != 'H' &&
	   row-1 >= 0 && row-1 < myGrid->getNumRows() && col >= 0 && col < myGrid->getNumCols())
	   {
		   if(myGrid->getLocation(row-1, col)->getDisplaySymbol() == 'o')// condition for recursive blasting
	    	{
	    		blast(row-1, col, myGrid);
	    	}
	    	if(myGrid->getLocation(row-1, col)->getDisplaySymbol() != 'E' && (myGrid->getLocation(row-1, col)->getWarp() == NULL) )
		    myGrid->getLocation(row-1, col)->setEmptySpace(emptyspace);//up
       }
    else if(myGrid->getLocation(row, col+1)->getDisplaySymbol() != 'P' && 
	   myGrid->getLocation(row, col+1)->getDisplaySymbol() != 'H')
    return 'l';
    else
    return 't';
    
	if(myGrid->getLocation(row, col-1)->getDisplaySymbol() != 'P' && 
	   myGrid->getLocation(row, col-1)->getDisplaySymbol() != 'H' &&
	   row >= 0 && row < myGrid->getNumRows() && col-1 >= 0 && col-1 < myGrid->getNumCols())
		{
		   if(myGrid->getLocation(row, col-1)->getDisplaySymbol() == 'o')// condition for recursive blasting
	    	{
	    		blast(row, col-1, myGrid);
	    	}
	    	if(myGrid->getLocation(row, col-1)->getDisplaySymbol() != 'E' && (myGrid->getLocation(row, col-1)->getWarp() == NULL) )
		    myGrid->getLocation(row, col-1)->setEmptySpace(emptyspace);//up
       }
   else if(myGrid->getLocation(row, col+1)->getDisplaySymbol() != 'P' && 
	   myGrid->getLocation(row, col+1)->getDisplaySymbol() != 'H')
    return 'l';
    else
    return 't';
    
	if(myGrid->getLocation(row+1, col)->getDisplaySymbol() != 'P' && 
	   myGrid->getLocation(row+1, col)->getDisplaySymbol() != 'H' &&
	   row+1 >= 0 && row+1 < myGrid->getNumRows() && col >= 0 && col < myGrid->getNumCols())
	  {
		   if(myGrid->getLocation(row+1, col)->getDisplaySymbol() == 'o')// condition for recursive blasting
	    	{
	    		blast(row+1, col, myGrid);
	    	}
	    	if(myGrid->getLocation(row+1, col)->getDisplaySymbol() != 'E' && (myGrid->getLocation(row+1, col)->getWarp() == NULL) )
		    myGrid->getLocation(row+1, col)->setEmptySpace(emptyspace);//up
       }
    else if(myGrid->getLocation(row, col+1)->getDisplaySymbol() != 'P' && 
	   myGrid->getLocation(row, col+1)->getDisplaySymbol() != 'H')
    return 'l';
    else
    return 't';
    
	if(myGrid->getLocation(row-1, col+1)->getDisplaySymbol() != 'P' && 
	   myGrid->getLocation(row-1, col+1)->getDisplaySymbol() != 'H' &&
	   row-1 >= 0 && row-1 < myGrid->getNumRows() && col+1 >= 0 && col+1 < myGrid->getNumCols())
	   {
		   if(myGrid->getLocation(row-1, col+1)->getDisplaySymbol() == 'o')// condition for recursive blasting
	    	{
	    		blast(row-1, col+1, myGrid);
	    	}
	    	if(myGrid->getLocation(row-1, col)->getDisplaySymbol() != 'E' && (myGrid->getLocation(row-1, col)->getWarp() == NULL) )
		    myGrid->getLocation(row-1, col+1)->setEmptySpace(emptyspace);//up
       }
    else if(myGrid->getLocation(row, col+1)->getDisplaySymbol() != 'P' && 
	   myGrid->getLocation(row, col+1)->getDisplaySymbol() != 'H')
    return 'l';
    else
    return 't';
    
	if(myGrid->getLocation(row-1, col-1)->getDisplaySymbol() != 'P' && 
	   myGrid->getLocation(row-1, col-1)->getDisplaySymbol() != 'H' &&
	   row-1 >= 0 && row-1 < myGrid->getNumRows() && col-1 >= 0 && col-1 < myGrid->getNumCols())
	   {
		   if(myGrid->getLocation(row-1, col-1)->getDisplaySymbol() == 'o')// condition for recursive blasting
	    	{
	    		blast(row-1, col-1, myGrid);
	    	}
	    	if(myGrid->getLocation(row-1, col-1)->getDisplaySymbol() != 'E' && (myGrid->getLocation(row-1, col-1)->getWarp() == NULL) )
		    myGrid->getLocation(row-1, col-1)->setEmptySpace(emptyspace);//up
       }
    else if(myGrid->getLocation(row, col+1)->getDisplaySymbol() != 'P' && 
	   myGrid->getLocation(row, col+1)->getDisplaySymbol() != 'H')
    return 'l';
    else
    return 't';
    
	if(myGrid->getLocation(row+1, col-1)->getDisplaySymbol() != 'P' && 
	   myGrid->getLocation(row+1, col-1)->getDisplaySymbol() != 'H' &&
	   row+1 >= 0 && row+1 < myGrid->getNumRows() && col-1 >= 0 && col-1 < myGrid->getNumCols())
	  {
		   if(myGrid->getLocation(row+1, col-1)->getDisplaySymbol() == 'o')// condition for recursive blasting
	    	{
	    		blast(row+1, col-1, myGrid);
	    	}
	    	if(myGrid->getLocation(row+1, col-1)->getDisplaySymbol() != 'E' && (myGrid->getLocation(row+1, col-1)->getWarp() == NULL) )
		    myGrid->getLocation(row+1, col-1)->setEmptySpace(emptyspace);//up
       }
   else if(myGrid->getLocation(row, col+1)->getDisplaySymbol() != 'P' && 
	   myGrid->getLocation(row, col+1)->getDisplaySymbol() != 'H')
    return 'l';
    else
    return 't';
    
	if(myGrid->getLocation(row+1, col+1)->getDisplaySymbol() != 'P' && 
	   myGrid->getLocation(row+1, col+1)->getDisplaySymbol() != 'H' &&
	   row+1 >= 0 && row+1 < myGrid->getNumRows() && col+1 >= 0 && col+1 < myGrid->getNumCols())
	   {
		   if(myGrid->getLocation(row+1, col+1)->getDisplaySymbol() == 'o')// condition for recursive blasting
	    	{
	    		blast(row+1, col+1, myGrid);
	    	}
	    	if(myGrid->getLocation(row+1, col+1)->getDisplaySymbol() != 'E' && (myGrid->getLocation(row+1, col+1)->getWarp() == NULL) )
		    myGrid->getLocation(row+1, col+1)->setEmptySpace(emptyspace);//up
       }
    else if(myGrid->getLocation(row, col+1)->getDisplaySymbol() != 'P' && 
	   myGrid->getLocation(row, col+1)->getDisplaySymbol() != 'H')
    return 'l';
    else
    return 't';
    
	emptyspace->setGrid(myGrid);
    return 't';	
}

// setting the location of bomb on the grid.
bool Bomb::setLocation(int row, int col, Grid *myGrid)
{
	GridLocation *cell = myGrid->getLocation(row, col);

	if(cell->getDisplaySymbol())
	{
    	cell->setBomb(this);
    	this->row = row;
    	this->col = col;

    	return true;
	}
    
    return false;
}

// placing the bomb on the desired row and col inthe grid
bool Bomb::placeBomb(int row, int col, Grid *myGrid)
{
	if(setLocation(row, col, myGrid) == '.' && row < myGrid->getNumRows() && row >= 0 &&
	               col >= 0 && col < myGrid->getNumCols())
	{
		this->setGrid(myGrid);
		return true;
	}
	
	return true;
	
}
