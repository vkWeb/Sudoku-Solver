/*************************
File: constraints.c
Author: Vivek Agrawal
Purpose: This file contains the definitions of functions required for constraint checking of the sudoku puzzle.
*************************/

#include <stdbool.h>

#include "constraints.h"

// Check if the value at `pos` in `sudokuBoard` exists in the horizontal row
// If exists return false else return true
static bool isHorizontallyValid(int sudokuBoard[], short int pos)
{
  // First member of row where `sudokuBoard[pos]` lies
  short int startPos = 9 * (pos / 9);
  for (short int i = startPos; i < startPos + 9; ++i)
  {
    if (sudokuBoard[i] == sudokuBoard[pos] && i != pos)
      return false;
  }
  return true;
}

// Check if the value at `pos` in `sudokuBoard` exists in the vertical column
// If exists return false else return true
static bool isVerticallyValid(int sudokuBoard[], short int pos)
{
  // First member of column where `sudokuBoard[pos]` lies
  short int startPos = pos % 9;
  for (short int i = startPos; i <= 72 + startPos; i += 9)
  {
    if (sudokuBoard[i] == sudokuBoard[pos] && i != pos)
      return false;
  }
  return true;
}

// Check if the value at `pos` in `sudokuBoard` exists in the 3x3 box
// If exists return false else return true
static bool isValidInBox(int sudokuBoard[], short int pos)
{
  // Row of first member of 3x3 box where `sudokuBoard[pos]` lies
  short int boxRow = 3 * ((pos / 9) / 3);
  // Column of first member of 3x3 box where `sudokuBoard[pos]` lies
  short int boxColumn = 3 * ((pos % 9) / 3);
  // First member of 3x3 box where `sudokuBoard[pos]` lies
  short int startPos = boxColumn + (9 * boxRow);

  for (short int i = 0, j = startPos; i < 3; ++i, j += 9)
  {
    for (short int k = j; k < (j + 3); ++k)
    {
      if (sudokuBoard[k] == sudokuBoard[pos] && k != pos)
        return false;
    }
  }
  return true;
}

// Check if the input value at `pos` is legal
bool isValueLegal(int sudokuBoard[], short int pos)
{
  return isHorizontallyValid(sudokuBoard, pos) && isVerticallyValid(sudokuBoard, pos) && isValidInBox(sudokuBoard, pos);
}
