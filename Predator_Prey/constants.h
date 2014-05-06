#ifndef CONSTANTS_H
#define CONSTANTS_H

//ratio combination : 150, 300 for 225 ptsize
//ratio combination : 50, 100 for
const int MAX_i =200;
const int MAX_j =400;

const int POINTSIZE =400;

const int TIMERDELAY = 25;

const int SCREENX = 1800;
const int SCREENY =900;

enum Dir { NONE = 0, LEFT = 1, RIGHT = 2, UP = 3, DOWN = 4}; //testing still
enum Gene { EMPTY = 0, WALL = 9, PREY = 1, PREDATOR = 2, MTLK_H = 50, MTLK_B = 51
           ,MTLK_E_O = 52, MTLK_E_S = 53};
#endif // CONSTANTS_H
