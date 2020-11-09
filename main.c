/*************************
File: main.c
Author: Vivek Agrawal
Purpose: Main program file for solving 9x9 sudoku puzzles using backtracking algorithm.

Test cases from: http://sudopedia.enjoysudoku.com/Test_Cases.html
*************************/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "constraints/constraints.h"

struct Game
{
    unsigned char board[81];
    int emptyCellIndices[81];
    int emptyCellIndicesArrSize;
};

// Solve sudoku by using backtracking
bool solveSudokuTillPos(unsigned char board[], int emptyCellIndices[], int emptyCellIndex)
{
    bool isSolved = true;
    int currentBoardPos = emptyCellIndices[emptyCellIndex];

    while (board[currentBoardPos] <= '9' && isSolved == true)
    {
        if (board[currentBoardPos] == '.')
        {
            board[currentBoardPos] = '1';
        }
        else
        {
            ++board[currentBoardPos];
        }

        if (board[currentBoardPos] > '9')
        {
            board[currentBoardPos] = '0';
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

int solveSudoku(unsigned char board[], int emptyCellIndices[], int emptyCellIndicesArrSize)
{
    if (emptyCellIndicesArrSize > 0)
    {
        int i = 0;
        while (i < emptyCellIndicesArrSize && solveSudokuTillPos(board, emptyCellIndices, i))
        {
            ++i;
        }

        if (emptyCellIndicesArrSize != i)
        {
            return -5;
        }
    }
    return 0;
}

// Main function
int main(void)
{
    // Declare a type of Game
    struct Game game;

    // Open file and check if its valid
    FILE *boardFile = fopen("board", "r");

    if (boardFile == NULL)
    {
        printf("error: can't open input file\n");
        return -1;
    }

    // Read game board from file
    game.emptyCellIndicesArrSize = 0;
    for (int i = 0; i < 81; ++i)
    {
        unsigned char c = fgetc(boardFile);

        if (c == '\n' || c == EOF)
        {
            if (i < 81)
            {
                printf("error: invalid number of elements in the board\n");
                return -2;
            }
            else
            {
                printf("error: some input error occured\n");
                return -3;
            }
        }

        if (c == '.')
        {
            game.emptyCellIndices[game.emptyCellIndicesArrSize] = i;
            ++game.emptyCellIndicesArrSize;
        }
        else if (c > '9' || c < '1')
        {
            printf("error: invalid board element found\n");
            return -4;
        }

        game.board[i] = c;
    }

    // Solve sudoku puzzle
    if (solveSudoku(game.board, game.emptyCellIndices, game.emptyCellIndicesArrSize) == -5)
    {
        printf("No solution found for the provided input board.\n");
        return -5;
    }

    // Print solved sudoku board
    for (int i = 0; i < 81; ++i)
    {
        printf("%c", game.board[i]);
    }

    printf("\n");
    fclose(boardFile);
    return 0;
}
