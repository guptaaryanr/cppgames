#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int height = 50, width = 50, score;
int snakex, snakey, fruitx, fruity;
char dir;
bool gameover;

void generation()
{
    gameover = false;
    snakex = height / 2;
    snakey = width / 2;

fruithor:
    fruitx = rand() % 50;
    if (fruitx == 0)
    {
        goto fruithor;
    }

fruitver:
    fruity = rand() % 50;
    if (fruity == 0)
    {
        goto fruitver;
    }

    score = 0;
}

void boundaries()
{
    system("cls");
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            if (i == 0 || j = 0 || i == width - 1 || j == height - 1)
            {
                printf("%s", "X");
            }
            else if (i == snakex && j == snakey)
            {
                printf("%s", "<");
            }
            else if (i == fruitx && j == fruity)
            {
                printf("%s", "0");
            }
            else
            {
                printf("");
            }
            printf("/n");
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
        default:
            continue;
        }
    }
}

void movement()
{
    sleep(0.01);
    switch (dir)
    {
    case 'u':
        --x;
        break;
    case 'l':
        --y;
        break;
    case 'd':
        ++x;
        break;
    case 'r':
        ++y;
        break;
    default:
        break;
    }

    if (x < 0 || x > height || y < 0 || y > width)
    {
        gameover = true;
    }

    if (snakex == fruitx && snakey == fruity)
    {
    fruitinitx:
        fruitx = rand() % 50;
        if (fruitx == 0)
        {
            goto fruitinitx;
        }
    fruitinity:
        fruity = rand() % 50;
        if (fruity == 0)
        {
            goto fruitinity;
        }
        score += 10;
    }
}

void main()
{
}