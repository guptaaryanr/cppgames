#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include <unistd.h>
#include <sys/ioctl.h>
#include <termios.h>

using namespace std;

int getch(void)
{
    struct termios oldattr, newattr;
    int ch;
    tcgetattr(STDIN_FILENO, &oldattr);
    newattr = oldattr;
    newattr.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newattr);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldattr);
    return ch;
}

void board()
{
    system("clear");
    printf("\n\n\t\t\t");
    for (int i = 0; i < 50; ++i)
    {
        printf("-");
    }
    printf("\n\t\t\t\t\tSnakes at position\n");
    printf("\t\t\t");
    for (int i = 0; i < 50; ++i)
    {
        printf("-");
    }
    printf("\n\t\t\t\t\t From 98 to 28");
    printf("\n\t\t\t\t\t From 95 to 24");
    printf("\n\t\t\t\t\t From 92 to 51");
    printf("\n\t\t\t\t\t From 83 to 19");
    printf("\n\t\t\t\t\t From 73 to 1");
    printf("\n\t\t\t\t\t From 69 to 33");
    printf("\n\t\t\t\t\t From 64 to 36");
    printf("\n\t\t\t\t\t From 59 to 17");
    printf("\n\t\t\t\t\t From 55 to 7");
    printf("\n\t\t\t\t\t From 52 to 11");
    printf("\n\t\t\t\t\t From 48 to 9");
    printf("\n\t\t\t\t\t From 46 to 5");
    printf("\n\t\t\t\t\t From 44 to 22 \n\n");
    printf("\t\t\t");
    for (int i = 0; i < 50; ++i)
    {
        printf("-");
    }
    printf("\n\t\t\t\t\tLadders at position\n");
    printf("\t\t\t");
    for (int i = 0; i < 50; ++i)
    {
        printf("-");
    }
    printf("\n\t\t\t\t\t From 8 to 26");
    printf("\n\t\t\t\t\t From 21 to 82");
    printf("\n\t\t\t\t\t From 43 to 77");
    printf("\n\t\t\t\t\t From 50 to 91");
    printf("\n\t\t\t\t\t From 62 to 96");
    printf("\n\t\t\t\t\t From 66 to 87");
    printf("\n\t\t\t\t\t From 80 to 100 \n\n");
    printf("\t\t\t");
    for (int i = 0; i < 50; ++i)
    {
        printf("-");
    }
    printf("\n");
}

void score(char n1[], char n2[], int p1, int p2)
{
    printf("\n\t\t\t");
    for (int i = 0; i < 50; ++i)
    {
        printf("-");
    }
    printf("\n\t\t\t\t\t\tStatus\n");
    printf("\t\t\t");
    for (int i = 0; i < 50; ++i)
    {
        printf("-");
    }
    printf("\n\t\t\t\t\t%s at position %d", n1, p1);
    printf("\n\t\t\t\t\t%s at position %d\n", n2, p2);
    printf("\t\t\t");
    for (int i = 0; i < 50; ++i)
    {
        printf("-");
    }
    printf("\n");
}

void play(int &score)
{
    int die = (rand() % 6 + 1);
    printf("\n\t\t\t\t\t\tDie rolled %d", die);
    score += die;
    printf("\n\t\t\t\t\t\tPosition: %d", score);
    switch (score)
    {
    case 98:
        score = 28;
        break;
    case 95:
        score = 24;
        break;
    case 92:
        score = 51;
        break;
    case 83:
        score = 19;
        break;
    case 73:
        score = 1;
        break;
    case 69:
        score = 33;
        break;
    case 64:
        score = 36;
        break;
    case 59:
        score = 17;
        break;
    case 55:
        score = 7;
        break;
    case 52:
        score = 11;
        break;
    case 48:
        score = 9;
        break;
    case 46:
        score = 5;
        break;
    case 44:
        score = 22;
        break;
    case 8:
        score = 26;
        break;
    case 21:
        score = 82;
        break;
    case 43:
        score = 77;
        break;
    case 50:
        score = 91;
        break;
    case 54:
        score = 93;
        break;
    case 62:
        score = 96;
        break;
    case 66:
        score = 87;
        break;
    case 80:
        score = 100;
    }
}

int main()
{
    int p1 = 0, p2 = 0, pos;
    char n1[50], n2[50];
    system("clear");
    printf("\t\t\t");
    for (int i = 0; i < 50; ++i)
    {
        printf("-");
    }
    printf("\n\n\n\t\t\t\t\tSnakes and Ladders by Aryan\n\n\n");
    printf("\t\t\t");
    for (int i = 0; i < 50; ++i)
    {
        printf("-");
    }
    printf("\n\t\t\t\t\tEnter player 1 name: ");
    cin >> n1;
    printf("\n\t\t\t\t\tEnter player 2 name: ");
    cin >> n2;
    while (p1 <= 100 && p2 <= 100)
    {
        board();
        score(n1, n2, p1, p2);
        cout << "\n\n\t\t\t\t\t" << n1;
        printf(" press any key to play");
        getch();
        pos = p1;
        play(p1);
        if (p1 < pos)
        {
            printf("\n\n\t\t\t\tYou found a snake and are now at position %d", p1);
        }
        else if (p1 > pos + 6)
        {
            printf("\n\n\t\t\t\tYou found a ladder and are now at position %d", p1);
        }
        cout << "\n\n\t\t\t\t\t" << n2;
        printf(" press any key to play");
        getch();
        pos = p2;
        play(p2);
        if (p2 < pos)
        {
            printf("\n\n\t\t\t\tYou found a snake and are now at position %d", p2);
        }
        else if (p2 > pos + 6)
        {
            printf("\n\n\t\t\t\tYou found a ladder and are now at position %d", p2);
        }
        getch();
    }
    system("clear");
    printf("\n\n\n\t\t\t");
    for (int i = 0; i < 50; ++i)
    {
        printf("-");
    }
    printf("\n\n\t\t\t\t\t\tResult\n\n");
    printf("\t\t\t");
    for (int i = 0; i < 50; ++i)
    {
        printf("-");
    }
    printf("\n");
    score(n1, n2, p1, p2);
    if (p1 >= p2)
    {
        cout << "\n\n\t\t\t\t\t"
             << n1;
        printf(" is the winner of the game\n\n");
    }
    else
    {
        cout << "\n\n\t\t\t\t\t"
             << n1;
        printf(" is the winner of the game\n\n");
    }
    getch();
}