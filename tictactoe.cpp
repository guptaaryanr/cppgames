#include <bits/stdc++.h>
using namespace std;

#define COMP 1
#define HUMAN 2
#define SIDE 3
#define COMPMOVE 'O'
#define HUMANMOVE 'X'

void board_status(char board[][SIDE])
{
    printf("\n\n");
    printf("\t\t\t %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("\t\t\t--------------\n");
    printf("\t\t\t %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("\t\t\t--------------\n");
    printf("\t\t\t %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
}

void instruction_display()
{
    printf("\t\t\t Tic-Tac-Toe by Aryan\n\n");
    printf("Choose a ceel from 1 to 9 as below\n\n");
    printf("\t\t\t 1 | 2 | 3 \n");
    printf("\t\t\t--------------\n");
    printf("\t\t\t 4 | 5 | 6 \n");
    printf("\t\t\t--------------\n");
    printf("\t\t\t 7 | 8 | 9 \n");
    printf("-\t-\t-\t-\t-\t-\t-\t-\t-\t-\n\n");
}

void init(char board[][SIDE], int moves[])
{
    srand(time(NULL));
    for (int i = 0; i < SIDE; ++i)
    {
        for (int j = 0; j < SIDE; ++j)
        {
            board[i][j] = ' ';
        }
    }
    for (int i = 0; i < SIDE * SIDE; ++i)
    {
        moves[i] = i;
    }
    random_shuffle(moves, moves + SIDE * SIDE);
}

void winner(int turn)
{
    if (turn == COMP)
    {
        printf("WINNER COMP\n");
    }
    else
    {
        printf("WINNER HUMAN\n");
    }
}

bool crossrow(char board[][SIDE])
{
    for (int i = 0; i < SIDE; ++i)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
        {
            return true;
        }
    }
    return false;
}

bool crosscolumn(char board[][SIDE])
{
    for (int i = 0; i < SIDE; ++i)
    {
        if (board[0][i] == board[i][1] && board[1][i] == board[2][i] && board[0][i] != ' ')
        {
            return true;
        }
    }
    return false;
}

bool crossdiag(char board[][SIDE])
{
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
    {
        return true;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
    {
        return true;
    }
    return false;
}

bool gameover(char board[][SIDE])
{
    return (crossrow(board) || crosscolumn(board) || crossdiag(board));
}

void play(int turn)
{
    char board[SIDE][SIDE];
    int moves[SIDE * SIDE];
    init(board, moves);
    instruction_display();
    int move = 0, x, y;
    while (!gameover(board) && move != SIDE * SIDE)
    {
        if (turn == COMP)
        {
            x = moves[move] / SIDE;
            y = moves[move] % SIDE;
            board[x][y] = COMPMOVE;
            printf("COMP has moved %c to cell %d\n", COMPMOVE, moves[move] + 1);
            board_status(board);
            ++move;
            turn = HUMAN;
        }
        else if (turn == HUMAN)
        {
            x = moves[move] / SIDE;
            y = moves[move] % SIDE;
            board[x][y] = HUMANMOVE;
            printf("HUMAN has moved %c to cell %d\n", HUMANMOVE, moves[move] + 1);
            board_status(board);
            ++move;
            turn = COMP;
        }
    }
    if (!gameover(board) && move == SIDE * SIDE)
    {
        printf("Draw\n");
    }
    else
    {
        if (turn == COMP)
        {
            turn = HUMAN;
        }
        else if (turn == HUMAN)
        {
            turn = COMP;
        }
        winner(turn);
    }
}

int main()
{
    play(COMP);
    return 0;
}