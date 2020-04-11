/*************************
File: constraints.h
Author: Vivek Agrawal
Purpose: This file contains the prototypes for functions defined in constraints.c.
*************************/

#include <stdbool.h>


// Check if the value at `pos` in `sudokuBoard` exists in the horizontal row
// If exists return false else return true
bool isHorizontallyValid(int sudokuBoard[], short int pos);


// Check if the value at `pos` in `sudokuBoard` exists in the vertical column
// If exists return false else return true
bool isVerticallyValid(int sudokuBoard[], short int pos);


// Check if the value at `pos` in `sudokuBoard` exists in the 3x3 box
// If exists return false else return true
bool isValidInBox(int sudokuBoard[], short int pos);
