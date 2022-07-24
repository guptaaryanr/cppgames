#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <sys/ioctl.h>
#include <termios.h>

// Had to find and copy functions for getch() and kbhit() as
// conio.h is not POSIX compatible and did not run properly on my system

bool kbhit()
{
    termios term;
    tcgetattr(0, &term);

    termios term2 = term;
    term2.c_lflag &= ~ICANON;
    tcsetattr(0, TCSANOW, &term2);

    int byteswaiting;
    ioctl(0, FIONREAD, &byteswaiting);

    tcsetattr(0, TCSANOW, &term);

    return byteswaiting > 0;
}

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

int height = 20, width = 20, score;
int snakex, snakey, fruitx, fruity;
char dir;
bool gameover;

void generation()
{
    gameover = false;
    snakex = height / 2;
    snakey = width / 2;

fruithor:
    fruitx = rand() % 20;
    if (fruitx == 0)
    {
        goto fruithor;
    }

fruitver:
    fruity = rand() % 20;
    if (fruity == 0)
    {
        goto fruitver;
    }

    score = 0;
}

void boundaries()
{
    system("clear");
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            if (i == 0 || j == 0 || i == (width - 1) || j == (height - 1))
            {
                printf("%s", "X");
            }
            else if (i == snakex && j == snakey)
            {
                printf("%s", "0");
            }
            else if (i == fruitx && j == fruity)
            {
                printf("%s", "*");
            }
            else
            {
                printf("%s", "");
            }
            printf("\n");
        }
    }
}

void keys()
{
    if (kbhit())
    {
        switch (getch())
        {
        case 'w':
            dir = 'u';
            break;
        case 'a':
            dir = 'l';
            break;
        case 's':
            dir = 'd';
            break;
        case 'd':
            dir = 'r';
            break;
        case 'x':
            gameover = true;
            break;
        }
    }
}

void movement()
{
    sleep(0.01);
    switch (dir)
    {
    case 'u':
        --snakex;
        break;
    case 'l':
        --snakey;
        break;
    case 'd':
        ++snakex;
        break;
    case 'r':
        ++snakey;
        break;
    default:
        break;
    }

    if (snakex < 0 || snakex > height || snakey < 0 || snakey > width)
    {
        gameover = true;
    }

    if (snakex == fruitx && snakey == fruity)
    {
    fruitinitx:
        fruitx = rand() % 20;
        if (fruitx == 0)
        {
            goto fruitinitx;
        }
    fruitinity:
        fruity = rand() % 20;
        if (fruity == 0)
        {
            goto fruitinity;
        }
        score += 10;
    }
}

int main()
{
    generation();
    boundaries();
    keys();
    while (!gameover)
    {
        movement();
    }
    return 0;
}