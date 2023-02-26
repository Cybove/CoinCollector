#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int playerX = 1;
int playerY = 1;
char player = 'P';

int enemyX = 8;
int enemyY = 7;
char enemy = 'E';

int enemyX2 = 17;
int enemyY2 = 5;
char enemy2 = 'E';

int enemyX3 = 28;
int enemyY3 = 9;
char enemy3 = 'E';

int enemyX4 = 35;
int enemyY4 = 3;
char enemy4 = 'E';

int direction = 1;
int direction2 = 1;
int direction3 = 1;
int direction4 = 1;

int coinX = 0;
int coinY = 0;
char coin = '+';

int sleepTime = 150;

int score = 0;

float timer = 0.0;

void hideCursor()
{
    CONSOLE_CURSOR_INFO cursor = {1, 0};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
}

void gotoxy(int x, int y)
{
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void print(int x, int y, char *str)
{
    gotoxy(x, y);
    printf("%s", str);
}

void printArea()
{
    printf("----------------------------------------\n");
    printf("|                                      |\n");
    printf("|                                      |\n");
    printf("|                                      |\n");
    printf("|                                      |\n");
    printf("|                                      |\n");
    printf("|                                      |\n");
    printf("|                                      |\n");
    printf("|                                      |\n");
    printf("|                                      |\n");
    printf("|                                      |\n");
    printf("----------------------------------------");
}

void printTimer()
{
    timer+=0.1;
    gotoxy(40,2);
    printf("Time: %.1f",timer);
}

void randomCoin()
{
    srand(time(NULL));
    coinX = rand() % 38 + 1;
    coinY = rand() % 10 + 1;
    if(coinX == playerX && coinY == playerY)
        randomCoin();
    else if(coinX == enemyX && coinX == enemyX2 && coinX == enemyX3 && coinX == enemyX4 && coinY == enemyY && coinY == enemyY2 && coinY == enemyY3 && coinY == enemyY4)
        randomCoin();
    else
        print(coinX, coinY, &coin);
}
void playerMove()
{
    char key = _getch();
    if (key == 'w' && playerY > 1)
    {
        print(playerX, playerY, " ");
        playerY--;
        print(playerX, playerY, &player);
    }
    else if (key == 's' && playerY < 10)
    {
        print(playerX, playerY, " ");
        playerY++;
        print(playerX, playerY, &player);
    }
    else if (key == 'a' && playerX > 1)
    {
        print(playerX, playerY, " ");
        playerX--;
        print(playerX, playerY, &player);
    }
    else if (key == 'd' && playerX < 38)
    {
        print(playerX, playerY, " ");
        playerX++;
        print(playerX, playerY, &player);
    }
        
}

void enemyMove()
{
    print(enemyX, enemyY, " ");
    enemyY += direction;
    print(enemyX, enemyY, &enemy);
    if (enemyY == 10)
        direction = -1;
    else if (enemyY == 1)
        direction = 1;

    print(enemyX2, enemyY2, " ");
    enemyY2 += direction2;
    print(enemyX2, enemyY2, &enemy2);
    if (enemyY2 == 10)
        direction2 = -1;
    else if (enemyY2 == 1)
        direction2 = 1;
    
    print(enemyX3, enemyY3, " ");
    enemyY3 += direction3;
    print(enemyX3, enemyY3, &enemy3);
    if (enemyY3 == 10)
        direction3 = -1;
    else if (enemyY3 == 1)
        direction3 = 1;

    print(enemyX4, enemyY4, " ");
    enemyY4 += direction4;
    print(enemyX4, enemyY4, &enemy4);
    if (enemyY4 == 10)
        direction4 = -1;
    else if (enemyY4 == 1)
        direction4 = 1;
}

void printScore()
{
    gotoxy(40, 1);
    printf("Score: %d", score);
}

void collectCoin()
{
    if (playerX == coinX && playerY == coinY)
    {
        score++;
        printScore();
        randomCoin();
        print(coinX, coinY, &coin);
    }
}

void printDifficulty(char *str)
{
    gotoxy(40, 3);
    printf("Difficulty: %s", str);
}

void getHarder()
{
    if(score >= 3)
    {
        sleepTime = 100;
        printDifficulty("         ");
        printDifficulty("Easy");
    }
    if(score >= 5)
    {
        sleepTime = 50;
        printDifficulty("         ");
        printDifficulty("Medium");
    }
    if(score >= 10)
    {
        sleepTime = 25;
        printDifficulty("         ");
        printDifficulty("Hard");
    }
        
    if(score >= 15)
    {
        sleepTime = 10;
        printDifficulty("         ");
        printDifficulty("Extreme");
    }
        
}

int checkCollision()
{
    if (playerX == enemyX && playerY == enemyY)
        {
            system("cls");
            printf("\tGame Over!\n");
            printf("\t    %d\n", score);
            printf("\tTime: %.1f",timer);
            return 1;
        }

    if (playerX == enemyX2 && playerY == enemyY2)
        {
            system("cls");
            printf("\tGame Over!\n");
            printf("\t    %d\n", score);
            printf("\tTime: %.1f",timer);
            return 1;
        }
    
    if (playerX == enemyX3 && playerY == enemyY3)
        {
            system("cls");
            printf("\tGame Over!\n");
            printf("\t    %d\n", score);
            printf("\tTime: %.1f",timer);
            return 1;
        }
    
    if (playerX == enemyX4 && playerY == enemyY4)
        {
            system("cls");
            printf("\tGame Over!\n");
            printf("\t    %d\n", score);
            printf("\tTime: %.1f",timer);
            return 1;
        }
    return 0;
}

int main()
{
    system("cls");
    hideCursor();
    printArea();
    printScore();
    printDifficulty("Very Easy");
    print(playerX, playerY, &player);
    randomCoin();
    print(coinX, coinY, &coin);
    while (1)
    {
        if(kbhit())
            playerMove();
        else
        {
            printTimer();
            getHarder();
            collectCoin();
            if(checkCollision())
                break;
            enemyMove();
            Sleep(sleepTime);
        }
    }
    return 0;
}