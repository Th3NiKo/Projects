#ifndef RANDOMIZER_H
#define RANDOMIZER_H
#include <cstdlib>
#include <ctime>
class Randomizer
{
    public:
        Randomizer();
        virtual ~Randomizer();


        //FUNCTIONS
        int randomize(int poczatek, int koniec);
        void initialize();

    protected:

    private:
};

#endif // RANDOMIZER_H
