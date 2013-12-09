#ifndef GAMEOFLIFE_H
#define GAMEOFLIFE_H

#include <fstream>
#include <unistd.h> 	//for windows use "Windows.h" /unix use : #include <unistd.h>
#include <ctime>
#include <cstdlib>
#include "mypanelopengl.h"
// #include <time.h> //Alternative to "ctime"




void mirror_edges(int world[][n+2]);
void random_World(int world[][n+2]);
void reset(int world[][n+2]);
void generate_World(int world[][n+2]);
void load_World(int world[][n+2]);
void write_World(const int world[][n+2]);
int life_Or_Death(int world[][n+2], int row, int col);
int save_pattern(int world[][n+2], int first_i, int first_j, int second_i, int second_j);


using namespace std;

void mirror_edges(int world[][n+2]) {
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

void reset(int world[][n+2]) {
        for (int i = 0; i < m+2; ++i)
            for (int j = 0; j < n+2; ++j)
                world[i][j] = 0;
    }

void write_World(const int world[][n+2]) {
        ofstream fout;
        fout.open("input.txt");
        for (int i = 1; i < m + 1; ++i) {
            for (int j = 1; j < n + 1; ++j)
                fout << world[i][j] << " ";
            fout << endl;
        }

        fout.close();
    }

int save_pattern(int world[][n+2], int first_i, int first_j, int second_i, int second_j) {
    int n = second_j - first_j + 1;
    int m = second_i - first_i + 1;
    ofstream fout;
    fout.open("saved_pattern.txt");
    fout << m << " " << n << " \n";
    for (int i = first_i; i < second_i + 1; ++i) {
        for (int j = first_j; j < second_j + 1; ++j)
            fout << world[i][j] << " ";
        fout << endl;
    }
    fout.close();
}



int life_Or_Death(int world[][n+2], int row, int col) {
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

void generate_World(int world[][n+2]) {
        int nextGen[m+2][n+2];
        for (int i = 1; i < m + 1; ++i)
            for (int j = 1; j < n + 1; ++j)
                nextGen[i][j] = life_Or_Death(world, i, j);
        for (int i = 1; i < m + 1; ++i)
            for (int j = 1; j < n + 1; ++j)
                world[i][j] = nextGen[i][j];
    }


void random_World(int world[][n+2]) {
        for (int i = 1; i < m+1; ++i)
            for (int j = 1; j < n+1 ; ++j)
                world[i][j] = rand() % 2;
    }

void load_World(int world[][n+2]) {
        ifstream fin;
        fin.open("input.txt");
        for (int i = 1; i < m + 1; ++i)
            for (int j = 1; j < n + 1; ++j)
                fin >> world[i][j];
        fin.close();
    }




#endif // GAMEOFLIFE_H
