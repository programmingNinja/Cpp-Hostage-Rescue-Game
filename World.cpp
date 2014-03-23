/*Description:
This is the implementation of the world class and it displays the entire world which includes the game status and the grid.
*/
#include <iomanip>
#include <iostream>
#include "World.h"
using namespace std;

// displays the current state of the game
void World::displayWorld()
{
	cout<<"-------------------------------------"<<endl;
	cout<<"Time: "<<setw(6)<<getTime()<<"  Moves:"<<setw(6)<<getMoves()<<endl;
	cout<<"Hostages:"<<setw(3)<<player->getHostRemain()<<"  Rescued:"<<setw(4)<<player->getHostRescued()<<endl;
	cout<<"Bombs:"<<setw(6)<<player->getBombCollected()<<"  Max Bombs:"<<setw(2)<<player->getMaxBomb()<<endl;
	cout<<"-------------------------------------"<<endl;	
	grid->display(cout);
}
