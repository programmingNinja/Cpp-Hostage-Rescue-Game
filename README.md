Author: Rohan D. Shah 
Project: Hostage Rescue

Cpp-Hostage-Rescue-Game
=======================
This is a game developed in cpp in which the player has to rescue hostages in the grid. He will have to face some 
obstacles while doing so and there would be some features that would help him do his task.


Game Description:
=================
The game is about a player rescuing the hostages. He has to navigate through the maze and reach out to hostages. 
He rescues a hostage when he reaches that cell position. The player has wall obstructing his path. In the way there 
are boxes which he can move. The player is also given a power of collecting bombs and deploying 
them. Once all the hostages are rescued the player has to move towards exit. Each maze has fixed amount time in 
which the player has to do his job. Once the player rescues all the hostage and reaches the exit in the maximum time 
allotted, he wins.
Rules:
======
1)	Player can’t move over the wall i.e. the wall obstructs his path
2)	Player can move only one box at a time and the box can move past only empty spaces.
3)	Player can collect only 3 bombs at a time. If he collects more, that bomb will disappear from the maze.
4)	Bomb will explode after 3 moves. 
5)	Player has to complete the rescue mission in allotted time
6)	Bomb cannot explode exit.
7)	If any of the hostage or the player gets exploded due to the bomb, the game is over and the player loses.
8)	If rescue mission is accomplished before time runs out, player wins the game.
9)	Player can use warps to get teleported to a destination cell.
10) Player can deploy only one bomb at a time.

Controls:
=========
The player is given various controls to move and perform various functions that will help him to win the game. The 
controls are as follows
1)	‘l’, ‘r’, ‘u’, ‘d’ to move left, right, up and down respectively.
2)	‘b[lrud]’ to deploy bomb. ‘l’, ‘r’, ‘u’, ‘d’ to deploy bomb on the left, right, up or down side of the player.
3)	‘q!’ to quit the game.
4)	 To wait and not do anything. Time will be counted though

Map Representation:
===================
There are two maps by default. These are called as the mazes or the grid in which the player will play the game. 
There are various objects inside the maze which are represented by the following notations/symbols.
1)	Wall: ‘X’
2)	Box: ‘B’
3)	Exit: ‘E’;
4)	Inactive Bomb: ‘o’ (ready to be picked)
5)	Active/Deployed Bomb: ‘@’
6)	Player: ‘P’
7)	Empty Space:’.’(period)
8)	Hostage: ‘H’

Note: Maps can be found in the "maps" folder. You can create your own map but be sure to maintain the structure of the 
map file and place it in the maps folder. The map file should be a txt file and should have the information in the 
manner it is in the default file otherwise the program will not read the map correctly.

Structure:
==========
The visualization of the design of the program is simple. There is a “world” which contains the entire game. It has all 
the status information like how many bombs are collected, how many hostages are rescued, etc. This world has the “grid” 
in which the game is being played. The grid is made up of grid cells which are called as “grid locations”. In these 
grid locations, “actors” are placed. These actors can be anything ranging from a wall to an empty space. These entities 
form different classes in the code. Some entities form member variables in the some other classes. All the map 
representation objects inherit the actor class. 

Classes and their functionality:
================================
1)	GridLocation:
It consists of all the actor object pointers as private member. This class has the methods to set these actor pointers 
and display their respective symbols on the grid locations. All the properties related to locations are kept in this 
class. 

2)	Grid:
This class contains all the grid locations in the form of 2D array which is a member variable. This class also has the 
integer variables to store the size of the entire maze. The display function is used to display the entire grid by 
taking the cells, their symbols and displaying them one by one.

3)	World:
This is the most important class as it contains the entire game. It has the player and the grid pointers as the member 
variable. Some of the status information is extracted from the player class and some status information is member 
variable of the class. With the grid and the player, the entire world can be displayed at once.

4)	Player: 
This class stores all the information of the player like its coordinates on the grid. This class has functions that 
enable the player to move on the grid and collect and deploy bombs. The player can also move boxes and hence there is a 
function to move them. The player inherits actor class and hence using the actor class, it can be set up on the grid at 
a specific grid location. It also has some variables that keep track of the state of the game like the hostages rescued 
and helps the world class to display the entire state.

5)	Actor:
This class is used to set all the other classes’ objects which inherit the actor class, on the grid. It also sets the 
symbols of the objects that inherit this class.

6)	Box:
This class has all the details about boxes on the maze. It has coordinates that keeps track of the boxes. This class 
inherits the actor class. Since the boxes can be moved, there are functions that facilitate movement of the boxes.

7)	Bomb:
This class inherits the actor class. It also has variables that store its location on the grid. Since the bombs can be 
placed, deployed, collected, blasted; the class has method for the same. 

8)	EmptySpace, Wall, Exit, Hostage:
They all inherit the actor class and can be kept on the grid with the methods inherited from actor class.

Purpose of this design:
=======================
The main aim to design the way it is designed was to keep everything related to one another in one class. The design 
depicts real world scenario in the sense that, the “world” has everything and hence in the program, it has the entire 
game. Even after keeping the related things together, it should not be cumbersome to perform functions on each other. 
I inherited the actor class because that made the code consistent and small since all the objects on the grid were 
actors and does more or less the same function. It was designed this way to keep in mind the scalability of the game. 
With this code it will be easy to add or remove few functionalities or features. 

Overall flow of the program:
============================
1)	The program read the available maps in the current directory. It presents the users a list of maps that he can play 
with. These maps are text files and can be selected by the user.

2)	These file names are stored in the vector and according to the user’s selection, the appropriate file at the 
respective index is loaded.

3)	The entire is file is read and stored in a 2D character array as is.

4)	The map also contains the max. number of rows and columns of the grid and the maximum time the user can take to 
finish the game.

5)	The map array elements are read one by one and stored into the grid. The actor objects are created depending on the 
symbol and placed on the grid at the particular location. 

6)	After the grid is initialized and ready, it is set in the world and the game begins.

7)	Then the program waits for the user input and performs accordingly.

Advance Feature: Warping
========================
This feature lets the player to get teleported from one cell to another. It is represented by numbers on the grid. To warp will have to same number to indicate the 
source and destination of the player. The bomb cannot destroy a warp entry or exit point. The player can get into one warp cell and get out of another mapped warp 
cell. The player can get into the warp cell from where he has come out, meaning a warp cell can act as a source as well as destination. There are total 10 warp 
points represented by numbers 1 to 10.

The game as a class called “Warp”. This class has the location information about a warp cell and inherits Actor class.  The player has an array which stores all the 
warp objects in the grid. Because of this, the code for warping becomes easy and scalable. In the main function, there are four arrays which store the location of the
warp point on the grid. Their index represents their symbol. Having the location of the warp points, we then initialize the warp objects.

Why not “auto exit” or “undo/redo”:
===================================
The problem I faced in implementing the undo/redo functionality was that I was storing pointers to different objects in 
a class. It is difficult to store a pointer’s value of the previous location as whenever you store a pointer, the 
latest location will get stored. This is the reason why I was unable to maintain the previous state
and hence I did not have any previous state to go to when the user wants to undo. I found the solution to this problem 
but it was too late. The solution was to make a deep copy of the pointer using a copy constructor and an operator function in the class.

Execution:
==========
1)Clone the repo
2)The project is already made is is named as "Project1"
3)Double click on that file, and the IDE which handles c++ projects will open. You need to install such IDE before 
running this file4)Execute the project and you will the console opening and you can play the game. There is not a need 
to build the project as the repo already has the .o file which is produced after compiling. But if your OS gives any 
trouble, compile it and then run it. Enjoy !!


[![Bitdeli Badge](https://d2weczhvl823v0.cloudfront.net/programmingNinja/cpp-hostage-rescue-game/trend.png)](https://bitdeli.com/free "Bitdeli Badge")

