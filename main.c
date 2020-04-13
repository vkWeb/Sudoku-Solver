/*************************
File: main.c
Author: Vivek Agrawal
Purpose: Main program file for solving 9x9 sudoku puzzles using backtracking algorithm.
*************************/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "constraints/constraints.h"

struct Game
{
  int board[81];
  int emptyCellIndices[81];
  int emptyCellIndicesArrSize;
};

// Solve sudoku by using backtracking
bool solveSudokuTillPos(int board[], int emptyCellIndices[], int emptyCellIndex)
{
  bool isSolvable = true;
  int currentBoardPos = emptyCellIndices[emptyCellIndex];

  while (board[currentBoardPos] <= 9 && isSolvable == true)
  {
    ++board[currentBoardPos];
    if (board[currentBoardPos] > 9)
    {
      board[currentBoardPos] = 0;
      if (emptyCellIndex == 0)
        isSolvable = false;
      else
        isSolvable = solveSudokuTillPos(board, emptyCellIndices, emptyCellIndex - 1);
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
  struct Game game;
  int board[81] = {0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 3, 0, 7, 4, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 2, 0, 8, 0, 0, 4, 0, 0, 1, 0, 6, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 7, 8, 0, 5, 0, 0, 0, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0};

  memcpy(game.board, board, sizeof(game.board));
  //memcpy(game.emptyCellIndices,, sizeof(game.board));
  game.emptyCellIndicesArrSize = 0;

  for (short int i = 0; i < 81; ++i)
  {
    if (game.board[i] == 0)
    {
      game.emptyCellIndices[game.emptyCellIndicesArrSize] = i;
      ++game.emptyCellIndicesArrSize;
    }
  }

  int i = 0;
  while (i != game.emptyCellIndicesArrSize && solveSudokuTillPos(game.board, game.emptyCellIndices, i))
    ++i;

  if (i != game.emptyCellIndicesArrSize)
    return -1;

  for (short int i = 0; i < 81; ++i)
  {
    if (i % 9 == 0)
      printf("\n");
    printf("%d ", game.board[i]);
  }

  return 0;
}
