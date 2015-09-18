#ifndef LION_H
#define LION_H
#include "Animal.hpp"
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <string>



class Lion : public Animal{
    
public:
    Lion();
    void deplace(int i);
    char nom();
    std::string attaquer();
};

#endif // LION_H
