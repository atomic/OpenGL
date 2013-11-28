
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



//void load_World(int world[][n+2]); //loading world from text file to 2D array

//void write_World(const int world[][n+2]); //writing down world from 2D arrays to text file
//void show_World(const int world[][n+2]); //show world in screen form
//void check_Edges(const int world[][n+2]); //check if edges are zeros (cout)
//void smoothen_Edges(int world[][n+2]); //assign zeros on edges of all newly created array
//void load_template(int world[][n+2]);

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

/*          DONT WORRY ABOUT THIS YET */
// void load_World(int world[][n+2])
//     {
//         ifstream fin;
//         fin.open("input.txt");
//         for (int i = 1; i < m + 1; ++i)
//             for (int j = 1; j < n + 1; ++j)
//                 fin >> world[i][j];
//         fin.close();
//         show_World(world);
//     } 

/*          DONT WORRY ABOUT THIS YET */
// void load_template(int world[][n+2])
//     {
//         int option, in_m, in_n;
//         cout << "Which template do you like to load?";
//         cout << "\n [1] Glider  [2] Pentomino [3] Pulsar [4] Exploder [5] 10 cells [6] spaceship\n >> ";
//         cin >> option;
//         cout << "Coordinate to load(m n) : ";
//         cin >> in_m;
//         cin >> in_n;
//         int row, col;
//         ifstream fin;
//         if (option == 1)
//             fin.open("glider.txt");
//         else if (option == 2)
//             fin.open("pentomino.txt");
//         else if (option == 3)
//             fin.open("pulsar.txt");
//         else if (option == 4)
//             fin.open("exploder.txt");
//         else if (option == 5)
//             fin.open("ten.txt");
//         else if (option == 6)
//             fin.open("spaceship.txt");
//         fin >> row;
//         fin >> col;
//         for (int i = in_m; i < in_m + row; ++i)
//             for (int j = in_n; j < in_n + col; ++j)
//                 fin >> world[i][j];

//     }

// void write_World(const int world[][n+2])
//     {
//         ofstream fout;
//         fout.open("input.txt");
//         for (int i = 1; i < m + 1; ++i) {
//             for (int j = 1; j < n + 1; ++j)
//                 fout << world[i][j] << " ";
//             fout << endl;
//         }

//         fout.close();
//     }

// void check_Edges(const int world[][n+2])
//     {
//         //Top edges
//         cout << "\nTop Edges: \t";
//         for (int j = 0; j < n + 2; ++j)
//             cout << world[0][j];
//         cout << "\nBot Edges: \t";
//         for (int j = 0; j < n + 2; ++j)
//             cout << world[m+1][j];
//         cout << "\nRight Edges: \t";
//         for (int i = 0; i < m + 2; ++i)
//             cout << world[i][0];
//         cout << "\nLeft Edges: \t";
//         for (int i = 0; i < m + 2; ++i)
//             cout << world[i][n+1];
//         cout << endl;
//     }



#endif // GAMEOFLIFE_H
