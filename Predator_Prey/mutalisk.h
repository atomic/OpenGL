#ifndef MUTALISK_H
#define MUTALISK_H
#include "organism.h"

class Mutalisk_H : public Organism
{
public:
    Mutalisk_H(Dir Ori = NONE);
    virtual void move(Organism *&target);
    virtual void evolve();
    virtual bool breedReady() const;
    virtual ~Mutalisk_H();
    virtual bool isStarved() const;
    //not use full actually
};

class Mutalisk_B : public Organism
{
public:
    Mutalisk_B();
    virtual void move(Organism *&target);
    virtual ~Mutalisk_B();
};

class Mutalisk_Egg_O : public Organism //ovum
{
public:
    Mutalisk_Egg_O();
    virtual void evolve();
    virtual bool breedReady() const; //not actually breed, but expand
    virtual ~Mutalisk_Egg_O();
};

class Mutalisk_Egg_S : public Organism //shell
{
public:
    Mutalisk_Egg_S();
    virtual void evolve();
    virtual ~Mutalisk_Egg_S();
};
#endif // MUTALISK_H
