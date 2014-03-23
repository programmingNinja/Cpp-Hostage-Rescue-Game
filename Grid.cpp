/*
Description:
This class represents the entire grid on which cells are placed. This is where the game is played and it acts as the ground
or the board for the game. It initializes the grid, sets its size, displays the entire grid and gets the location of all the cells

Method:
1)initGrid()
2)destructor
3)setGridSize()
4)getLocation
5)display
Author: Rohan D. Shah
*/
#include <cstdlib>
using namespace std;

#include "grid.h"
#include "GridLocation.h"

void Grid::initGrid() {
    // allocate memory and init array
    grid = new GridLocation*[n_rows];
    for (int i = 0; i < n_rows; i++)
        grid[i] = new GridLocation[n_cols];
}

// setting the max size of the grid
void Grid::setGridSize(int n_rows, int n_cols) {
    this->n_rows = n_rows;
    this->n_cols = n_cols;
    initGrid();
}

Grid::~Grid() {
    // release memory
    for (int i = 0; i < n_rows; i++)
        delete grid[i];
    delete[] grid;
}
// Gets the particular cell on the grid.
GridLocation *Grid::getLocation(int row, int col) {
    if (row < 0 || row >= n_rows || col < 0 || col >= n_cols)
        return NULL;
    return &grid[row][col];
}

// displays the grid
void Grid::display(std::ostream & os) {
    for (int row = 0; row < n_rows; row++) {
        for (int col = 0; col < n_cols; col++)
            os << grid[row][col].getDisplaySymbol();
        os << endl;
    }
    cout<<endl;
}


