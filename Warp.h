
#ifndef WARP_H
#define WARP_H

#include "Actor.h"

/**
 * Language: C++
 * IDE: Dev-C++ 5.4.2
 * Author: Rohan D. Shah
 * 
 * Description:
 * An empty space that can be travelled through from source cell to the destination cell.
 */
class Warp : public Actor
{
private:
	int srcRow;
	int srcCol;
	int destRow;
	int destCol;
public:
	Warp(){}
    Warp(char symbol) : Actor(symbol) {}
    virtual ~Warp() {}

    virtual char getDisplaySymbol() { return symbol; }
    
    void setsrcRow(int srcRow) { this->srcRow = srcRow; }
    void setsrcCol(int srcCol) { this->srcCol = srcCol; }
    void setdestRow(int destRow) { this->destRow = destRow; }
    void setdestCol(int destCol) { this->destCol = destCol; }
    
    int getsrcRow() { return srcRow; }
    int getsrcCol() { return srcCol; }
    int getdestRow() { return destRow; }
    int getdestCol() { return destCol; }
    
    
    bool warp() {}
    
};

#endif // WARP_H
