// Required header files
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// To do:
//  - fix segmentation fault

// Create a reversed linked list
typedef struct node
{
  int row, col, n;
  struct node *prev;
} node;

node *latest = NULL;

// Global suduko board, row and column position
int BOARD[9][9] = {{5, 3, 0, 0, 7, 0, 0, 0, 0}, {6, 0, 0, 1, 9, 5, 0, 0, 0}, {0, 9, 8, 0, 0, 0, 0, 6, 0}, {8, 0, 0, 0, 6, 0, 0, 0, 3}, {4, 0, 0, 8, 0, 3, 0, 0, 1}, {7, 0, 0, 0, 2, 0, 0, 0, 6}, {0, 6, 0, 0, 0, 0, 2, 8, 0}, {0, 0, 0, 4, 1, 9, 0, 0, 5}, {0, 0, 0, 0, 8, 0, 0, 7, 9}};
int ROW = 0, COLUMN = 0;

// Check if there's a zero (empty cell)
bool checkZero(void)
{
  while (ROW < 9)
  {
    while (COLUMN < 9)
    {
      if (BOARD[ROW][COLUMN] == 0)
      {
        return true;
      }
      COLUMN++;
    }
    ROW++;
  }
  return false;
}

// Check row constraint
bool checkRow(int row, int col)
{
  for (int i = 0; i < 9; i++)
  {
    if (BOARD[row][col] == BOARD[row][i])
      return false;
  }
  return true;
}

// Check column constraint
bool checkColumn(int row, int col)
{
  for (int i = 0; i < 9; i++)
  {
    if (BOARD[row][col] == BOARD[i][col])
      return false;
  }
  return true;
}

// Check box constraint
bool checkBox(int row, int col)
{
  int i = row - (row % 3);
  int j = col - (col % 3);

  while (i < i + 3)
  {
    while (j < j + 3)
    {
      if (BOARD[row][col] == BOARD[i][j] && row != i && col != j)
        return false;
      j++;
    }
    i++;
  }
  return true;
}

// Solve sudoku by using backtracking (a brute force approach)
int solveSudoku(node *currentNode)
{
  currentNode->n = currentNode->n + 1;
  while (checkRow(currentNode->row, currentNode->col) == false || checkColumn(currentNode->row, currentNode->col) == false || checkBox(currentNode->row, currentNode->col) == false)
  {
    currentNode->n = currentNode->n + 1;
    if (currentNode->n == 10)
    {
      currentNode->n = 0;
      (currentNode->prev)->n = solveSudoku(currentNode->prev);
      currentNode->n = currentNode->n + 1;
    }
  }
  return currentNode->n;
}

// Main function
int main(void)
{
  // Keep on solving until we reach the final zero (empty cell)
  while (checkZero() == true)
  {
    node *newNode = malloc(sizeof(node));
    newNode->prev = latest;
    latest = newNode;

    newNode->row = ROW;
    newNode->col = COLUMN;
    newNode->n = solveSudoku(newNode);
  }

  // Print solved sudoku board
  for (int i = 0; i < 9; i++)
  {
    for (int j = 0; j < 9; j++)
    {
      printf("%d ", BOARD[i][j]);
    }
    printf("\n");
  }

  return 0;
}
