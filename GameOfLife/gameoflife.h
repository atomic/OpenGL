#ifndef GAMEOFLIFE_H
#define GAMEOFLIFE_H

#include <iostream>
#include <fstream>
#include <unistd.h> 	//for windows use "Windows.h" /unix use : #include <unistd.h>
#include <ctime>
#include <cstdlib>
// #include <time.h> //Alternative to "ctime"


const int m = 50;
const int n = 50;

void mirror_edges(int world[][n+2]);
int life_Or_Death(int world[][n+2], int row, int col);
void random_World(int world[][n+2]);
void reset(int world[][n+2], int n);
void generate_World(int world[][n+2]);

using namespace std;


void mirror_edges(int world[][n+2])
    {
        for (int i = 1; i < m+1; ++i)
            world[i][n+1] = world[i][1];
        for (int i = 1; i < m+1; ++i)
            world[i][0] = world[i][n];
        for (int j = 1; j < n+1; ++j)
            world[0][j] = world[m][j];
        for (int j = 1; j < n+1; ++j)
            world[m+1][j] = world[1][j];
        world[0][0] = world[m][n];
        world[0][n+1] = world[m][1];
        world[m+1][0] = world[1][n];
        world[m+1][n+1] = world[1][1];
    }

void reset(int world[][n+2], int n)
    {
        for (int i = 1; i < m+1; ++i)
            for (int j = 1; j < n+1; ++j)
                world[i][j] = 0;
    }

int life_Or_Death(int world[][n+2], int row, int col)
    {
        int aliveN = 0;
        int state = world[row][col];
        for (int i = row - 1; i < row + 2; ++i)
            for (int j = col - 1; j < col + 2; ++j)
                aliveN += world[i][j];
        if (state == 1)
            aliveN -= 1;
        if (aliveN == 3 && state == 0)
            return 1;
        else if ((aliveN == 3 || aliveN == 2) && state == 1)
            return 1;
        else
            return 0;
    }

void generate_World(int world[][n+2])
    {
        int nextGen[m+2][n+2];
        for (int i = 1; i < m + 1; ++i)
            for (int j = 1; j < n + 1; ++j)
                nextGen[i][j] = life_Or_Death(world, i, j);
        for (int i = 1; i < m + 1; ++i)
            for (int j = 1; j < n + 1; ++j)
                world[i][j] = nextGen[i][j];
    }


void random_World(int world[][n+2])
    {
        for (int i = 1; i < m+1; ++i)
            for (int j = 1; j < n+1 ; ++j)
                world[i][j] = rand() % 2;
    }



#endif // GAMEOFLIFE_H
