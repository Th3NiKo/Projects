#include "Randomizer.h"

Randomizer::Randomizer()
{

}

Randomizer::~Randomizer()
{

}

int Randomizer::randomize(int poczatek, int koniec)
{
    return (std::rand() % (koniec - poczatek + 1) ) + poczatek; //koniec  - poczatek + 1
}


void Randomizer::initialize()
{
    srand( time( NULL ) );
}
