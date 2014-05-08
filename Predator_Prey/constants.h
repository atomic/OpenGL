#ifndef CONSTANTS_H
#define CONSTANTS_H

//ratio for ASUS : i 200, j 400, ptSize 400, 1800x900
//ratio for DELL :
const int MAX_i =75;
const int MAX_j =150;

const int POINTSIZE =200;

const int TIMERDELAY = 25;

const int SCREENX =700;
const int SCREENY =300;

enum Dir { NONE = 0, LEFT = 1, RIGHT = 2, UP = 3, DOWN = 4}; //testing still
enum Gene { EMPTY = 0, WALL = 9, PREY = 1, PREDATOR = 2, MTLK_H = 50, MTLK_B = 51
           ,MTLK_E_O = 52, MTLK_E_S = 53};
#endif // CONSTANTS_H
