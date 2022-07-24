#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int rules(char player, char comp)
{
    if (player == comp)
    {
        return 0;
    }
    else if (player == 'r' && comp == 'p')
    {
        return -1;
    }
    else if (player == 'r' && comp == 's')
    {
        return 1;
    }
    else if (player == 'p' && comp == 's')
    {
        return -1;
    }
    else if (player == 'p' && comp == 'r')
    {
        return 1;
    }
    else if (player == 's' && comp == 'r')
    {
        return -1;
    }
    else if (player == 's' && comp == 'p')
    {
        return 1;
    }
    else
    {
        return 2;
    }
}

int main()
{
    char comp, player, next;
    printf("\n\t\t\t\t\tRock, Paper, Scissors by Aryan\n");
    printf("\t\t\t\t");
    for (int i = 0; i < 50; ++i)
    {
        printf("-");
    }
    printf("\n\t\t\t\tRock: r\t\tPaper: p\tScissors: s\n");
    printf("\t\t\t\t");
    for (int i = 0; i < 50; ++i)
    {
        printf("-");
    }
    printf("\n");
    do
    {
        int num = 0;
        srand(time(0));
        num = rand() % 100;
        if (num < 33)
        {
            comp = 'r';
        }
        else if (num > 66)
        {
            comp = 's';
        }
        else
        {
            comp = 'p';
        }
        printf("\t\t\t\tChoose: ");
        cin >> player;
        int result = rules(player, comp);
        if (result == 1)
        {
            printf("\t\t\t\tComputer played %c\n", comp);
            printf("\t\t\t\tPlayer wins\n");
        }
        else if (result == -1)
        {
            printf("\t\t\t\tComputer played %c\n", comp);
            printf("\t\t\t\tComputer wins\n");
        }
        else if (result == 2)
        {
            printf("\t\t\t\tComputer played %c\n", comp);
            printf("\t\t\t\tInvalid choice");
        }
        else
        {
            printf("\t\t\t\tComputer played %c\n", comp);
            printf("\t\t\t\tTie\n");
        }
        printf("\t\t\t\tPlay again?\n");
        printf("\t\t\t\tPress any key to continue or 'x' to exit: ");
        cin >> next;
        printf("\t\t\t\t");
        for (int i = 0; i < 50; ++i)
        {
            printf("-");
        }
        printf("\n");
    } while (next != 'x');

    return 0;
}