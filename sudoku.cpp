#include <iostream>
#include <stdio.h>

using namespace std;

#define GRID 9

int board[GRID][GRID] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0}};

// int board[GRID][GRID] =
//     {
//         {0, 0, 6, 5, 0, 8, 4, 0, 0},
//         {5, 2, 0, 0, 0, 1, 0, 0, 0},
//         {0, 7, 8, 0, 0, 0, 0, 0, 1},
//         {0, 0, 4, 0, 1, 0, 0, 8, 0},
//         {9, 0, 0, 8, 2, 3, 0, 0, 5},
//         {0, 5, 0, 0, 9, 0, 6, 0, 0},
//         {1, 3, 0, 0, 0, 0, 2, 5, 0},
//         {0, 0, 0, 0, 0, 0, 0, 7, 4},
//         {0, 0, 5, 2, 0, 6, 3, 0, 0}};

int cnt = 0;

void generate()
{
    int row = rand() % 9;
    int col = rand() % 9;
    int num = (rand() % 9 + 1);
    if (board[row][col] == 0)
    {
        ++cnt;
        board[row][col] = num;
    }
}

bool checkCol(int col, int num)
{
    for (int row = 0; row < GRID; ++row)
    {
        if (board[row][col] == num)
        {
            return true;
        }
    }
    return false;
}

bool checkRow(int row, int num)
{
    for (int col = 0; col < GRID; ++col)
    {
        if (board[row][col] == num)
        {
            return true;
        }
    }
    return false;
}

bool checkGroup(int row, int col, int num)
{
    for (int r = 0; r < 3; ++r)
    {
        for (int c = 0; c < 3; ++c)
        {
            if (board[r + row][c + col] == num)
            {
                return true;
            }
        }
    }
    return false;
}

void game()
{
    for (int row = 0; row < GRID; ++row)
    {
        for (int col = 0; col < GRID; ++col)
        {
            if (col == 3 || col == 6)
            {
                printf(" | ");
            }
            printf("%d ", board[row][col]);
        }
        if (row == 2 || row == 5)
        {
            printf("\n");
            for (int i = 0; i < GRID; ++i)
            {
                printf("----");
            }
        }
        printf("\n");
    }
}

bool findGroup(int &row, int &col)
{
    for (row = 0; row < GRID; ++row)
    {
        for (col = 0; col < GRID; ++col)
        {
            if (board[row][col] == 0)
            {
                return true;
            }
        }
        return false;
    }
    return false;
}

bool canEnter(int row, int col, int num)
{
    return (!checkRow(row, num) && !checkCol(col, num) && !checkGroup(row - row % 3, col - col % 3, num));
}

bool solution()
{
    int row, col;
    if (!findGroup(row, col))
    {
        return true;
    }
    for (int num = 1; num <= 9; ++num)
    {
        if (canEnter(row, col, num))
        {
            board[row][col] = num;
            if (solution())
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    for (int i = 0; i < 81; ++i)
    {
        if (cnt < 32)
        {
            generate();
        }
        else
        {
            break;
        }
    }
    if (solution())
    {
        game();
    }
    else
    {
        printf("Cannot be solved\n");
    }
}
