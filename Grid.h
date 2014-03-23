
#ifndef GRID_H
#define GRID_H

#include <iostream>

class GridLocation;
/**
 * Language: C++
 * IDE: Dev-C++ 5.4.2
 * Author: Rohan D. Shah
 * 
 * Description:
 * The game grid.
 * It contains gridcells. This is the playing area 
 * where user will perform actions.
 */
class Grid 
{
private:

    /** Total Number of rows and columns of the grid (maximum size). */
    int n_rows;
    int n_cols;

    /** 2D array for the grid. */
    GridLocation **grid;

    /** Create an empty grid. */
    void initGrid();

public:
    Grid() {}; /** Does nothing */
    virtual ~Grid() ;
    int getNumRows() { return n_rows; }
    int getNumCols() { return n_cols; }

    GridLocation *getLocation(int row, int col);
	void setGridSize(int n_rows, int n_cols);
    void display(std::ostream & os);
};

#endif // GRID_H


