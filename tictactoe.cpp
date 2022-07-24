#include <iostream>
using namespace std;

char board[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

int game_status()
{
    if (board[1] == board[2] && board[2] == board[3])
    {
        return 1;
    }
    else if (board[4] == board[5] && board[5] == board[6])
    {
        return 1;
    }
    else if (board[7] == board[8] && board[8] == board[9])
    {
        return 1;
    }
    else if (board[1] == board[4] && board[4] == board[7])
    {
        return 1;
    }
    else if (board[2] == board[5] && board[5] == board[8])
    {
        return 1;
    }
    else if (board[3] == board[6] && board[6] == board[9])
    {
        return 1;
    }
    else if (board[1] == board[5] && board[5] == board[9])
    {
        return 1;
    }
    else if (board[3] == board[5] && board[5] == board[7])
    {
        return 1;
    }
    else if (board[1] != '1' && board[2] != '2' && board[3] != '3' && board[4] != '4' && board[5] != '5' && board[6] != '6' && board[7] != '7' && board[8] != '8' && board[9] != '9')
    {
        return 0;
    }
    else
    {
        return -1;
    }
}

void draw_board()
{
    system("clear");
    printf("\n\n\tTic Tac Toe by Aryan\n\n");
    printf("\tP1 (x) - P2 (o)\n\n\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[1], board[2], board[3]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[4], board[5], board[6]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[7], board[8], board[9]);
    printf("     |     |     \n");
}

int main()
{
    int player = 1, block, status;
    char token;
    do
    {
        draw_board();
        player = (player % 2) ? 1 : 2;
        printf("Player %d, enter block (1-9): ", player);
        cin >> block;
        token = (player == 1) ? 'x' : 'o';
        if (block == 1 && board[1] == '1')
        {
            board[1] = token;
        }
        else if (block == 2 && board[2] == '2')
        {
            board[2] = token;
        }
        else if (block == 3 && board[3] == '3')
        {
            board[3] = token;
        }
        else if (block == 4 && board[4] == '4')
        {
            board[4] = token;
        }
        else if (block == 5 && board[5] == '5')
        {
            board[5] = token;
        }
        else if (block == 6 && board[6] == '6')
        {
            board[6] = token;
        }
        else if (block == 7 && board[7] == '7')
        {
            board[7] = token;
        }
        else if (block == 8 && board[8] == '8')
        {
            board[8] = token;
        }
        else if (block == 9 && board[9] == '9')
        {
            board[9] = token;
        }
        else
        {
            printf("Invalid");
            --player;
            cin.ignore();
            cin.get();
        }
        status = game_status();
        ++player;
    } while (status == -1);
    draw_board();
    if (status == 1)
    {
        printf("\aPlayer %d wins", --player);
    }
    else
    {
        printf("\aDraw");
    }
    cin.ignore();
    cin.get();
    return 0;
}