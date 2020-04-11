/*************************
File: main.c
Author: Vivek Agrawal
Purpose: Main program file
*************************/

#include <stdio.h>
#include <stdbool.h>

#include "constraints/constraints.h"

// Solve sudoku by using backtracking (a brute force approach)
bool solveSudoku(int board[], int pos/*, int emptyCellIndices[]*/)
{
  bool isSolvable = true;

  while (board[pos] <= 9 && isSolvable == true)
  {
    ++board[pos];
    if (board[pos] > 9)
    {
      board[pos] = 0;
      if ((pos = findPrevious(board, pos)) == -1)
        isSolvable = false;
      else
        isSolvable = solveSudoku(board, pos);
    }

    else if (isValueValid(board, pos))
    {
      isSolvable = true;
      break;
    }
  }

  return isSolvable;
}

// Main function
int main(void)
{
  int sudokuBoard[] = {5, 3, 0, 0, 7, 0, 0, 0, 0, 6, 0, 0, 1, 9, 5, 0, 0, 0, 0, 9, 8, 0, 0, 0, 0, 6, 0, 8, 0, 0, 0, 6, 0, 0, 0, 3, 4, 0, 0, 8, 0, 3, 0, 0, 1, 7, 0, 0, 0, 2, 0, 0, 0, 6, 0, 6, 0, 0, 0, 0, 2, 8, 0, 0, 0, 0, 4, 1, 9, 0, 0, 5, 0, 0, 0, 0, 8, 0, 0, 7, 9};
  int emptyCellIndices[] = {2, 3, 5, 6, 7, 8, 10, 11, 15, 16, 17, 18};
  return 0;
}
