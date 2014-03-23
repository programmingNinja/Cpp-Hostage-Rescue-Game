/*
Description:
This class represents the player. It contains functions which enables the player to do all the task which he is suppose to do.
The player can push boxes, collect and place bombs, rescue hostages, move in the grid or player going through a warp cell.
Methods:
1)setLocation()
2)collectBomb()
3)move()

Author: Rohan D. Shah
*/
#include <iostream>
#include <stdlib.h> 
using namespace std;
#include "World.h"
#include "Grid.h"
#include "GridLocation.h"
#include "Box.h"
#include "Player.h"
#include "Bomb.h"

// setting the location of the player on the grid
bool Player::setLocation(int row, int col) {
    GridLocation *cell = grid->getLocation(row, col);

    // invalid location
    if (cell == NULL)
        return false;

    // there is a wall on the cell already
    if (cell->getDisplaySymbol() == 'X')
    {
    	cout<<"Player cannot move over a wall or push it."<<endl;
    	return false;
    }

    // valid location
    grid->getLocation(this->row, this->col)->setPlayer(NULL); // remove from old location
    cell->setPlayer(this);
    this->row = row;
    this->col = col;

    return true;
}

// player collecting the bomb
bool Player::collectBomb(int row, int col) {
    GridLocation *cell = grid->getLocation(row, col);

    // invalid location
    if (cell == NULL)
        return false;

    // nothing to collect
    if (cell->getBomb() == NULL)
        return false;
        
    // cannot collect more than three bombs    
    if(bombCollectedValue == 3)
    {
    	// bomb being dropped and not collected
    	Bomb *b = new Bomb();
    	b = cell->getBomb();
    	// remove bomb from map
    	cell->setBomb(NULL);
    	cout<<"Player already has maximum bomb, it cannot collect more, so the bomb was dropped"<<endl;
    	delete b;
		return false;
    }    	

    // pick up bomb
    cell->setBomb(NULL);
    // setting new location for the player
    setLocation(row, col);

    setBombCollected(getBombCollected()+1);     

    return true;
}

// player moving the grid
char Player::move(int dx, int dy, Grid *myGrid, World *myWorld) {
        // determine new location
        int newRow = row + dx;
        int newCol = col + dy;
        				   		   
        // try to move
        GridLocation *newCell = grid->getLocation(newRow, newCol);
        
		if (newCell != NULL && newCell->getDisplaySymbol() == '.') {
            setLocation(newRow, newCol);
            myGrid->getLocation(newRow, newCol)->setPlayer(this);
            return 't';
        }
        
        // if player tries to move to exit
        if(newCell != NULL && newCell->getDisplaySymbol() == 'E')
        {
        	
        	// check the exit condition.
        	// if that is true return success
        	if(getHostRemain() == 0 )
		   	{
		   		cout<<"SUCCESS, you WON!!"<<endl;
		   		return 'w';
		   	}
		   	else
		   	{
		   		cout<<"Rescue all the hostages first, to exit"<<endl;
		   		return 'f';
		   	}
		   	
        	
        }
        
        // player tries to collect bomb
        if(newCell != NULL && newCell->getDisplaySymbol() == 'o')
        {
        	bool res = collectBomb(newRow, newCol);
        	if(res)
        	cout<<"Congrats, the player collected a bomb"<<endl;
        	setLocation(newRow, newCol);
        	myGrid->getLocation(newRow, newCol)->setPlayer(this);
        	return 't';
        }
        
        // player tries to move box
        if(newCell != NULL && newCell->getDisplaySymbol() == 'B')
        {
        	Box *box = new Box();
        	box->setLocation(newRow, newCol, grid, true);
        	if(box->move(dx, dy, myGrid))
        	{
        		box->setGrid(myGrid);
        		newCell->setBox(NULL);
        		setLocation(newRow, newCol);
        		newCell->setPlayer(this);
        		myGrid->getLocation(newRow, newCol)->setPlayer(this);
        		cout<<"Player moved the box"<<endl;
				return 't';        		
        	}
        	return 'f';
			
        }
        
        //player rescuing hostages
        if(newCell != NULL && newCell->getDisplaySymbol() == 'H')
        {
        	hostRescued++; 
			hostRemain--;
        	newCell->setHost(NULL);
        	setLocation(newRow, newCol);
        	myGrid->getLocation(newRow, newCol)->setPlayer(this);
        	cout<<"Good progress, player rescued a hostage"<<endl;
        	if(hostRemain == 0)
        	cout<<"All hostages rescued, now move towards the exit"<<endl;
        	return 't';			
        }
                
        if(newCell != NULL && (newCell->getWarp() != NULL))
		{
			
			newCell->setPlayer(NULL);
			int warpRow, warpCol;
			warpRow = warps[1].getdestRow();
			warpCol = warps[1].getdestCol();
			
			for(int t=1 ; t<10 ; t++)
			{
				if(newCell->getDisplaySymbol()-'0' == t)
				{	warpRow = this->getWarp(t).getsrcRow();
					warpCol = this->getWarp(t).getsrcCol();
								
					if(warpRow == newRow && warpCol == newCol)
					{
						warpRow = this->getWarp(t).getdestRow();
						warpCol = this->getWarp(t).getdestCol();
					}
					myGrid->getLocation(row, col)->setPlayer(NULL);				
					setLocation(warpRow, warpCol);
					myGrid->getLocation(warpRow, warpCol)->setPlayer(this);
					myWorld->setPlayer(this);
					myWorld->setGrid(myGrid);
					cout<<"The player was teleported"<<endl;
					break;
				}
			}
			
			return 't';
		}
        
    return 'f';
}

