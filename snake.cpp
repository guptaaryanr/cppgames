#include <stdlib.h>
#include <stdio.h>

// Had to find and copy functions for getch() and kbhit() as
// conio.h is not POSIX compatible and did not run properly on my system
#include <unistd.h>
#include <sys/ioctl.h>
#include <termios.h>

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

int height = 20, width = 20, score, dir;
int snakex, snakey, fruitx, fruity;
bool gameover;

void fruit()
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
}

void borders()
{
    system("clear");
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            if (i == 0 || j == 0 || i == width - 1 || j == height - 1)
            {
                printf("#");
            }
            else
            {
                if (i == snakex && j == snakey)
                {
                    printf("0");
                }
                else if (i == fruitx && j == fruity)
                {
                    printf("*");
                }
                else
                {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }

    printf("Score: %d\n", score);
    printf("Press X to quit");
}

void buttons()
{
    if (kbhit())
    {
        switch (getch())
        {
        case 'w':
            dir = 1;
            break;
        case 'a':
            dir = 2;
            break;
        case 's':
            dir = 3;
            break;
        case 'd':
            dir = 4;
            break;
        case 'x':
            gameover = true;
            break;
        }
    }
}

void move()
{
    sleep(0.01);
    switch (dir)
    {
    case 1:
        --snakex;
        break;
    case 2:
        --snakey;
        break;
    case 3:
        ++snakex;
        break;
    case 4:
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
    fruitreachx:
        fruitx = rand() % 20;
        if (fruitx == 0)
        {
            goto fruitreachx;
        }
    fruitreachy:
        fruity = rand() % 20;
        if (fruity == 0)
        {
            goto fruitreachy;
        }
        score += 10;
    }
}

int main()
{
    borders();
    buttons();
    while (!gameover)
    {
        fruit();
        move();
    }
    return 0;
}