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
    bool isSolved = true;
    int currentBoardPos = emptyCellIndices[emptyCellIndex];

    while (board[currentBoardPos] <= 9 && isSolved == true)
    {
        ++board[currentBoardPos];
        if (board[currentBoardPos] > 9)
        {
            board[currentBoardPos] = 0;
            if (emptyCellIndex == 0)
            {
                isSolved = false;
            }
            else
            {
                isSolved = solveSudokuTillPos(board, emptyCellIndices, emptyCellIndex - 1);
            }
        }
        else if (isValueLegal(board, currentBoardPos))
        {
            isSolved = true;
            break;
        }
    }

    return isSolved;
}

// Main function
int main(void)
{
    struct Game game;
    game.emptyCellIndicesArrSize = 0;

    FILE *boardFile = fopen("board", "r");

    if (boardFile == NULL)
    {
        printf("error: can't open input file\n");
        return -1;
    }

    for (int i = 0; i < 81; ++i)
    {
        if (fscanf(boardFile, "%d", &game.board[i]) != 1)
        {
            printf("error: can't read input file\n");
            return -2;
        }

        if (game.board[i] == 0)
        {
            game.emptyCellIndices[game.emptyCellIndicesArrSize] = i;
            ++game.emptyCellIndicesArrSize;
        }
    }

    int i = 0;
    while (i != game.emptyCellIndicesArrSize && solveSudokuTillPos(game.board, game.emptyCellIndices, i))
    {
        ++i;
    }

    if (i != game.emptyCellIndicesArrSize)
    {
        printf("error: the given sudoku board can't be solved\n");
        return -3;
    }

    for (int i = 0; i < 81; ++i)
    {
        if (i % 9 == 0)
        {
            printf("\n");
        }
        printf("%d ", game.board[i]);
    }

    printf("\n");
    return 0;
}
