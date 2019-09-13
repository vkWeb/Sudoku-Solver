#include <stdio.h>
#include <stdbool.h>

int sudukoBoard[9][9] = {{3, 8, 0, 7, 0, 0, 6, 0, 2}, {4, 0, 2, 0, 8, 0, 0, 3, 0}, {1, 7, 5, 6, 0, 0, 4, 9, 0}, {0, 0, 0, 0, 0, 9, 0, 7, 0}, {7, 0, 0, 8, 0, 3, 0, 0, 9}, {0, 9, 0, 5, 0, 0, 0, 0, 0}, {0, 1, 3, 0, 0, 8, 9, 6, 4}, {0, 2, 0, 0, 5, 0, 8, 0, 3}, {6, 0, 8, 0, 0, 1, 0, 2, 5}};
int rowPos = 0, columnPos = 0;

bool checkZero(void)
{
  for (; rowPos < 9; rowPos++)
  {
    for (; columnPos < 9; columnPos++)
    {
      if (sudukoBoard[rowPos][columnPos] == 0)
      {
        return true;
      }
    }
  }
  return false;
}

void incrementByOne(void)
{
  if (checkZero() == true)
  {
    sudukoBoard[rowPos][columnPos]++;
  }
}

bool checkRow(void)
{
  for (int i = 0; i < 9; i++)
  {
    if (sudukoBoard[rowPos][columnPos] == sudukoBoard[rowPos][i])
      return false;
  }
  return true;
}

bool checkColumn(void)
{
  for (int i = 0; i < 9; i++)
  {
    if (sudukoBoard[rowPos][columnPos] == sudukoBoard[i][columnPos])
      return false;
  }
  return true;
}

bool checkBox(void)
{
  int i = rowPos - (rowPos % 3);
  int j = columnPos - (columnPos % 3);

  for (; i < i + 3; i++)
  {
    for (; j < j + 3; j++)
    {
      if (sudukoBoard[rowPos][columnPos] == sudukoBoard[i][j] && rowPos != i && columnPos != j)
        return false;
    }
  }
  return true;
}

int main(void)
{
  return 0;
}