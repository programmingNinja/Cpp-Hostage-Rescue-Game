
/**
 * Language: C++
 * IDE: Dev-C++ 5.4.2
 * Author: Rohan D. Shah
 * 
 * Description:
 * Simple game where a player moves around a grid
 * collecting bombs, moving boxes, rescuing hostages.
 * he wins by rescuing all the hostages and reaching the
 * the exit in time
 * For more information please read "ReadMe.txt"
 */

#include "libraries.h"
using namespace std;
#include "includeFiles.h"

/**
 * Print status and grid.
 */
void updateDisplay(World &myWorld) 
{
    myWorld.displayWorld();
}

// dislplays rules
void showRules ()
{
	cout<<"----------------------------------------------------------------------------"<<endl;
    cout<<"Rules:"<<endl;
	cout<<"----------------------------------------------------------------------------"<<endl;
	cout<<"1)	Player can’t move over the wall i.e. the wall obstructs his path"<<endl;
	cout<<"2)	Player can move only one box at a time and the box can move past"<<endl;
	cout<<"	only empty spaces."<<endl;
	cout<<"3)	Player can collect only 3 bombs at a time. If he collects more, "<<endl;
	cout<<"     	that bomb will disappear from the maze."<<endl;
	cout<<"4)	Bomb will explode after 3 moves."<<endl;
	cout<<"5)	Player has to complete the rescue mission in allotted time"<<endl;
	cout<<"6)	Bomb cannot explode exit."<<endl;
	cout<<"7)	If any of the hostage or the player gets exploded due to the bomb, "<<endl;
	cout<<"     	the game is over and the player loses."<<endl;
	cout<<"8)	If rescue mission is accomplished before time runs out, player wins"<<endl;
	cout<<"     	the game."<<endl;
	cout<<"9)	Player can use warps to get teleported to a destination cell."<<endl;
	cout<<"-----------------------------------------------------------------------------"<<endl<<endl;
}
// displays what symbols are represented and how
void showMapRepresentation ()
{
	cout<<"-----------------------------------------------------------------------------"<<endl;
	cout<<"Map Representation:"<<endl;
	cout<<"-----------------------------------------------------------------------------"<<endl;
	cout<<"There are two maps by default. These are called as the mazes or the grid in "<<endl;
	cout<<"which the player will play the game. "<<endl;
	cout<<"There are various objects inside the maze which are "<<endl;
	cout<<"represented by the following notations/symbols."<<endl;
	cout<<"1)	Wall: X"<<endl;
	cout<<"2)	Box: B"<<endl;
	cout<<"3)	Exit: E"<<endl;
	cout<<"4)	Inactive Bomb: o (ready to be picked)"<<endl;
	cout<<"5)	Active/Deployed Bomb: @"<<endl;
	cout<<"6)	Player: P"<<endl;
	cout<<"7)	Empty Space:.(period)"<<endl;
	cout<<"8)	Hostage: H"<<endl;
	cout<<"----------------------------------------------------------------------------"<<endl<<endl;
}

// how to navigate through the game and make moves
void showControls()
{
	cout<<"-----------------------------------------------------------------------------"<<endl;
	cout<<"Controls:"<<endl;
	cout<<"-----------------------------------------------------------------------------"<<endl;
	cout<<"The player is given various controls to move and perform various functions "<<endl;
	cout<<"that will help him to win the game."<<endl; 
	cout<<"The controls are as follows"<<endl;
	cout<<"1)	l, r, u, d to move left, right, up and down respectively."<<endl;
	cout<<"2)	bl, bd, bu, br to deploy bomb on the left, down, up and right side of "<<endl;
	cout<<"     	the player, respectively."<<endl;
	cout<<"3)	q! to quit the game."<<endl;
	cout<<"4)	To wait and not do anything. Time will be counted though"<<endl;
	cout<<"---------------------------------------------------------------------------"<<endl;
}

void showHelp ()
{
	showRules();
	showMapRepresentation();
	showControls();
}
void showAbout()
{
	cout<<"----------------------------------"<<endl;
	cout<<"Game Name: Hostage Rescue"<<endl;
	cout<<"Developer: Rohan D. Shah"<<endl;
	cout<<"----------------------------------"<<endl;
}
int main() 
{
	start:
	vector<string> fileNames; //stores all the file names in the directory
	string dir_name = "./maps"; // current directory
	DIR *dir;
	struct dirent *ent;
	struct stat filestat;
	int i=1;
	
	// for warping, stores the warps positions
	int warpRow1[10];
	int warpCol1[10];
	int countOcc[10];
	int warpRow2[10];
	int warpCol2[10];
	
	for(int a=0 ; a<10 ; a++)
	{
		warpRow1[a] = 10;
		warpCol1[a] = 10;
		countOcc[a] = 0;
		warpRow2[a] = 10;
		warpCol2[a] = 10;
	}
	
	int rows,columns,time; // to initialize the grid and world
	int play_row,play_col; // tracks player position
	int host = 0; // tracks number of hostages in the maze
	bool bombDeployed = false; // checks of bomb is deployed or not. value is true if deployed
	int deployedAtX, deployedAtY; // position of the bomb deployed on the maze
	
	// for counting the moves so that bomb can be exploded after 3 moves
	int count = 0; 
	string move_choice; // to input the moves of the user
	ifstream gameMap;
	World myWorld;
	Grid myGrid;
	Player *player = new Player();
	int choice;
	cout<<"Welcome to the 'Hostage Rescue' game. Press enter to continue"<<endl;
	start1:
		cin.clear();
		cin.ignore();
	
	cout<<"________________________________________"<<endl;
	cout<<"Welcome to the well-made game"<<endl;
	cout<<"----------------------------------------"<<endl;
	cout<<"1. Load the maze"<<endl;
	cout<<"2. Help" <<endl;
	cout<<"3. About"<<endl;
	cout<<"_________________________________________"<<endl;
	
	cin>>choice;
	cout<<endl;	
		if(choice == 1)		
		{			    		
			int maze_choice;
			cout<<"__________________________________________________________________"<<endl;
			cout<<"Load the maze menu. select your maze                              "<<endl;
			cout<<"------------------------------------------------------------------"<<endl;
			if ((dir = opendir (dir_name.c_str())) != NULL) {
		        /* print all the files and directories within directory */
		        cout << "Printing all the files in current directory..." << endl << endl;
		
		        while ((ent = readdir (dir)) != NULL) {
		            // Skip the file if it is invalid or it is a directory
		            string filepath = dir_name + "/" + ent->d_name;
		            if (stat( filepath.c_str(), &filestat ))
		                continue;
		            if (S_ISDIR( filestat.st_mode ))
		                continue;
		            cout << i<<")"<<ent->d_name << endl;
		            i++;
		            fileNames.push_back(ent->d_name); // storing in the vector
		        }
		        closedir (dir);
		    }
		    else 
			{
		        /* could not open directory */
		        cerr << strerror(errno) << endl;
		        return EXIT_FAILURE;
		    }
			cout<<"__________________________________________________________________"<<endl;
			cin>>maze_choice;
			//Loading the required level form maps folder
			for(int j=0 ; j<fileNames.size() ; j++)
			{
				if(j == maze_choice-1)
				{
					string fileName = ".\\maps\\"+fileNames.at(j);
					gameMap.open(fileName.c_str());
				}
				
			}
		
			// check bounds of file
			if(gameMap.fail())
			{
				cout << "error opening the file" << endl;
				exit(1);
			}
			else 
			{
				// taking the rows and column of the grid as well as the maximum moves a player can 
				//make in the form of time
				gameMap >> rows >> columns >> time;
		
				// declaring a 2-d array to store the map
				char **map = new char*[rows];
				// storing the entire maze on the grid from the map array
				for(int i=0; i<rows; i++)
				{
					map[i] = new char[columns];	
				}
				char ch = gameMap.get();
		
				// Initialising the map to declared 2-d array
				for (int r=0; r<rows; r++)
				{
					int c=0;
					char ch = gameMap.get();
					while(ch!='\n' && !gameMap.eof())
					{
						map[r][c] = ch;
						c++;
						ch = gameMap.get();
					}
				}
				gameMap.close();
				
				// creating a world object and initialising its rows, columns and time-limit values
				myWorld.setTime(time);
				myWorld.setMaxTime(time);
				// creating the required grid
				myGrid.setGridSize(rows,columns);
				// reading the map point by point
				for(int i=0 ; i<rows ; i++)
				{				
					for(int j=0 ; j<columns ; j++)
					{
						// positioning the actors and putting them onto the grid
						if(map[i][j] == 'X')
						{
							Wall *wall = new Wall();
							wall->setGrid(&myGrid);
							myGrid.getLocation(i, j)->setWall(wall);
						}
						else if(map[i][j] == 'B')
						{
							Box *box = new Box();
							box->setGrid(&myGrid);
							myGrid.getLocation(i, j)->setBox(box);
						}
						else if(map[i][j] == 'o')
						{
							Bomb *bomb = new Bomb() ;
							bomb->setGrid(&myGrid);
							myGrid.getLocation(i, j)->setBomb(bomb);
						}
						else if(map[i][j] == 'E')
						{
							Exit *exitt = new Exit() ;
							exitt->setGrid(&myGrid);
							myGrid.getLocation(i, j)->setExit(exitt);
						}
						else if(map[i][j] == 'P')
						{							
							myGrid.getLocation(i, j)->setPlayer(player);
							play_row = i;
							play_col = j;
							player->setGrid(&myGrid);
							player->setLocation(i,j);
						}
						else if(map[i][j] == 'H')
						{
							Hostage *hostage = new Hostage();							
							hostage->setGrid(&myGrid);
							myGrid.getLocation(i, j)->setHost(hostage);
							host++;
						}
						else if(map[i][j] == '.')
						{
							EmptySpace *emptyspace = new EmptySpace();
							emptyspace->setGrid(&myGrid);
							myGrid.getLocation(i, j)->setEmptySpace(emptyspace);
						}
						else
						{
							Warp *warp = new Warp(map[i][j]);
							warp->setSymbol(map[i][j]);												
							warp->setGrid(&myGrid);		
							myGrid.getLocation(i, j)->setWarp(warp);						
							if(countOcc[map[i][j] - '0'] > 0)
							{
								warpRow2[map[i][j] - '0'] = i;
								warpCol2[map[i][j] - '0'] = j;
							}
							else
							{
								warpRow1[map[i][j] - '0'] = i;
								warpCol1[map[i][j] - '0'] = j;
							}
							countOcc[map[i][j] - '0']++;
						}
					}
				}
				myGrid.display(cout);
				for(int t=0;t<10;t++)
				{
					if(countOcc[t]>0)
					{
						Warp *warp = new Warp();
						warp->setSymbol(t+'0');
						warp->setsrcRow(warpRow1[t]);
						warp->setsrcCol(warpCol1[t]);
						warp->setdestRow(warpRow2[t]);
						warp->setdestCol(warpCol2[t]);				
						player->setWarps(warp);
					}
				}				
				myWorld.setGrid(&myGrid); // setting the grid on the world				
				// intitializing the status of the game
				myWorld.setTime(time);
				myWorld.setMoves(0);
				myWorld.setPlayer(player);
				player->setBombCollected(0);
				player->setMaxBomb(3);
				player->setHostRemain(host);
				player->setHostRescued(0);
			}
		}
		if(choice == 2)
		{
			showHelp();	
			cout<<"Press Enter to continue:";
			cin.get();
			goto start1;
		}			
					
		if(choice == 3)	
		//write about
		{
			showAbout();
			cout<<"Press Enter to continue:";
			cin.get();
			goto start1;	
		}
		else if(choice != 1 && choice != 2 && choice != 3 )		
		{
			cout<<"invalid input."<<endl;
			goto start1;
		}
		
	
	updateDisplay(myWorld);
		
	play:
	// checking if the player ran out of time, if yes, hes loses
	if(myWorld.getMoves() == myWorld.getMaxTime())
	{
		cout<<"FAILURE, you ran out of time"<<endl;
		goto stop;
	}
	cout<<"Enter your move as left(l), right(r), up(u), down(d), wait(w),"<<endl<<"deploy bomb(bu,bd,br,bl), quit (q!)"<<endl;
	cin>>move_choice;
	cout<<endl;	
	if(bombDeployed)
	count++;
	// if player has moves three places after deploying the bomb, the deployed bomb will blast
	if(count == 3 && bombDeployed)
	{
		//blast bomb;
		char res;
		Bomb *bomb = new Bomb();
		res = bomb->blast(deployedAtX, deployedAtY, &myGrid);
		
		if(res == 'l')
		{
			cout<<"FAILURE, you bombed the player or hostage"<<endl;
			goto stop;
		}
		if(res = 't')//bomb blasted successfully
		{
			myWorld.setGrid(&myGrid);
			updateDisplay(myWorld);
			bombDeployed = false;			
			count = 0;
			cout<<"Bomb blasted....baammmmm!!"<<endl;
		}
	}	
	//deploying the bomb
	if(move_choice == "bl" || move_choice == "bu" || move_choice == "bd" || move_choice == "br" && !bombDeployed)
	{
		if(player->getBombCollected()>0)
		{
			if(move_choice == "bl")
			{
				// placing bomb at the left of the player
				// check if it is an emptyspace
				// if yes place the bomb
				// decreement the the bomb count
				// put the activated symbol
				// update world
				// get the above grid cell
					if(myGrid.getLocation(player->getRow(), player->getCol()-1)->getDisplaySymbol() == '.')
					{
						Bomb *bomb = new Bomb();
						bomb->setSymbol('@');
						bomb->placeBomb(player->getRow(), player->getCol()-1, &myGrid);
						player->setBombCollected(player->getBombCollected()-1);	
						updateDisplay(myWorld);
						bombDeployed = true;
						deployedAtX = player->getRow();
						deployedAtY = player->getCol()-1;
						cout<<"You placed the bomb on the left side."<<endl<<endl;
						goto play;
						
					}
					else
					{
						// you cannot place bomb on wall, box, exit, hostage
						cout<<"You cannot place the bomb there"<<endl<<endl;
						goto play;
					}					
				}
				if(move_choice == "br")
				{
					//get the above grid cell
					//check if it is an emptyspace
					//if yes place the bomb
					//decreement the the bomb count
					//put the activated symbol
					//update world
					if(myGrid.getLocation(player->getRow(), player->getCol()+1)->getDisplaySymbol() == '.')
					{
						Bomb *bomb = new Bomb();
						bomb->setSymbol('@');
						bomb->placeBomb(player->getRow(), player->getCol()+1, &myGrid);
						player->setBombCollected(player->getBombCollected()-1);	
						updateDisplay(myWorld);
						bombDeployed = true;
						deployedAtX = player->getRow();
						deployedAtY = player->getCol()+1;
						cout<<"You placed the bomb on the right side."<<endl<<endl;
						goto play;
					}
					else
					{
						// you cannot place bomb on wall, box, exit, hostage
						cout<<"You cannot place the bomb there"<<endl<<endl;
						goto play;
					}
				
				}
				if( move_choice == "bu" )
				{
					// get the above grid cell
					// check if it is an emptyspace
					// if yes place the bomb
					// decreement the the bomb count
					// put the activated symbol
					// update world
					if(myGrid.getLocation(player->getRow()-1, player->getCol())->getDisplaySymbol() == '.')
					{
						Bomb *bomb = new Bomb();
						bomb->setSymbol('@');
						bomb->placeBomb(player->getRow()-1, player->getCol(), &myGrid);
						player->setBombCollected(player->getBombCollected()-1);	
						updateDisplay(myWorld);
						deployedAtX = player->getRow()-1;
						deployedAtY = player->getCol();
						bombDeployed = true;
						cout<<"You placed the bomb above."<<endl<<endl;
						goto play;
					}
					else
					{
						// you cannot place bomb on wall, box, exit, hostage
						cout<<"You cannot place the bomb there"<<endl<<endl;
						goto play;
					}				
				}
				
				if(move_choice == "bd")
				{
					// get the above grid cell
					// check if it is an emptyspace
					// if yes place the bomb
					// decreement the the bomb count
					// put the activated symbol
					// update world
					if(myGrid.getLocation(player->getRow()+1, player->getCol())->getDisplaySymbol() == '.')
					{
						Bomb *bomb = new Bomb();
						bomb->setSymbol('@');
						bomb->placeBomb(player->getRow()+1, player->getCol(), &myGrid);
						player->setBombCollected(player->getBombCollected()-1);	
						updateDisplay(myWorld);
						bombDeployed = true;
						deployedAtX = player->getRow()+1;
						deployedAtY = player->getCol();
						cout<<"You placed the bomb below."<<endl<<endl;
						goto play;
					}	
					else
					{
						// you cannot place bomb on wall, box, exit, hostage
						cout<<"You cannot place the bomb there"<<endl<<endl;
						goto play;
					}				
				}
		}
		else// dont have bombs but still trying to deploy
		{
			
			cout<<"You dont have enough bombs to be deployed"<<endl<<endl;
			goto play;
		}
	}
	// moving the player
	if(move_choice == "l")
	{
		myWorld.setMoves(myWorld.getMoves()+1);
        myWorld.setTime(myWorld.getTime()-1);
		char res = player->move(0, -1, &myGrid, &myWorld);
		if(res == 't')
		{
			play_col--;
			player->setGrid(&myGrid);
		}
		if(res == 'l' || res == 'w')
		goto stop;
		myWorld.setGrid(&myGrid);
		updateDisplay(myWorld);
		cout<<"The player moved left."<<endl<<endl;
		goto play;
	}
	if(move_choice == "d")
	{
		myWorld.setMoves(myWorld.getMoves()+1);
        myWorld.setTime(myWorld.getTime()-1);
		char res = player->move(1, 0, &myGrid, &myWorld);
		if(res == 't')
		{
			play_row++;
			player->setGrid(&myGrid);
		}
		if(res == 'l' || res == 'w')
		goto stop;
		myWorld.setGrid(&myGrid);
		updateDisplay(myWorld);
		cout<<"The player moved down."<<endl<<endl;
		goto play;
	}
	if(move_choice == "u")
	{
		myWorld.setMoves(myWorld.getMoves()+1);
        myWorld.setTime(myWorld.getTime()-1);
		char res = player->move(-1, 0, &myGrid, &myWorld);
		if(res == 't')
		{
			play_row--;
			player->setGrid(&myGrid);
		}
		if(res == 'l' || res == 'w')
		goto stop;
		myWorld.setGrid(&myGrid);
		updateDisplay(myWorld);
		cout<<"The player moved up."<<endl<<endl;
		goto play;
	}
	if(move_choice == "r")
	{
		myWorld.setMoves(myWorld.getMoves()+1);
        myWorld.setTime(myWorld.getTime()-1);
		char res = player->move(0,1, &myGrid, &myWorld);
		if(res == 't')
		{
			play_col++;
			player->setGrid(&myGrid);
		}
		if(res == 'l' || res == 'w')
		goto stop;
		myWorld.setGrid(myWorld.getGrid());
		updateDisplay(myWorld);
		cout<<"The player moved right."<<endl<<endl;
		goto play;
	}
	if(move_choice == "w")	
	{
		myWorld.setMoves(myWorld.getMoves()+1);
        myWorld.setTime(myWorld.getTime()-1);
        myWorld.setGrid(myWorld.getGrid());
		updateDisplay(myWorld);
		cout<<"Player waited for one step."<<endl<<endl;
		goto play;
	}
	if(move_choice == "q!")
	{
		cout<<"you decided to leave the game. Bye bye"<<endl;
		goto stop;
	}
	
	else 
	{
		cout<<"Your input was wrong."<<endl<<endl;
		goto play;
	}
	// clearing memory
	stop:
	delete[] dir;
	delete[] ent;	
	return 0;
}
