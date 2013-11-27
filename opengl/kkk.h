#ifndef KKK_H
#define KKK_H
#include <iostream>
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>
#include <time.h>
using namespace std;

const int Size=10;
void setInt(int aI[]);
void clearSet(int aI[]);
void setOne(int aI[]);

void setInt(int aI[])
{
    clearSet(aI);
    setOne(aI);
}

void clearSet(int aI[])
{
    for(int i=0;i<Size;i++)
        aI[i]=0;
}

void setOne(int aI[])
{
    srand (time(NULL));
    aI[rand()%Size]=1;
}

#endif // KKK_H
