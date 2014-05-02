#ifndef CONSTANTS_H
#define CONSTANTS_H

const int MAX_i = 150;
const int MAX_j = 300;

const int POINTSIZE = 225;

const int SCREENX = 800;
const int SCREENY = 400;

enum Dir { NONE = 0, LEFT = 1, RIGHT = 2, UP = 3, DOWN = 4}; //testing still
enum Gene { WALL = 9, PREY = 1, PREDATOR = 2, MTLK_H = 50, MTLK_B = 51};
#endif // CONSTANTS_H
