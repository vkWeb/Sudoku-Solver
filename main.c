/*************************
File: main.c
Author: Vivek Agrawal
Purpose: Main program file
*************************/

#include <stdio.h>
#include <stdbool.h>

#include "constraints/constraints.h"

// Solve sudoku by using backtracking
bool solveSudokuTillPos(int board[], int emptyCellIndex, int emptyCellPos[])
{
  bool isSolvable = true;
  int currentBoardPos = emptyCellPos[emptyCellIndex];

  while (board[currentBoardPos] <= 9 && isSolvable == true)
  {
    ++board[currentBoardPos];
    if (board[currentBoardPos] > 9)
    {
      board[currentBoardPos] = 0;
      if (emptyCellIndex == 0)
        isSolvable = false;
      else
        isSolvable = solveSudoku(board, currentBoardPos);
    }

    else if (isValueLegal(board, currentBoardPos))
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
  int sudokuBoard[81] = {5, 3, 0, 0, 7, 0, 0, 0, 0, 6, 0, 0, 1, 9, 5, 0, 0, 0, 0, 9, 8, 0, 0, 0, 0, 6, 0, 8, 0, 0, 0, 6, 0, 0, 0, 3, 4, 0, 0, 8, 0, 3, 0, 0, 1, 7, 0, 0, 0, 2, 0, 0, 0, 6, 0, 6, 0, 0, 0, 0, 2, 8, 0, 0, 0, 0, 4, 1, 9, 0, 0, 5, 0, 0, 0, 0, 8, 0, 0, 7, 9};
  int emptyCellPos[81];
  for (short int i = 0, j = 0; i < 81; ++i)
  {
    if (sudokuBoard[i] == 0)
    {
      emptyCellPos[j] = i;
      ++j;
    }
  }

  int i = 0;
  while (solveSudokuTillPos(sudokuBoard, i, emptyCellPos))
    ++i;

  return 0;
}
