#ifndef LION_H
#define LION_H
#include "Animal.hpp"
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <string>



class Lion : public Animal{
    
public:
    //Constructeur et destructeur
    Lion();
    virtual ~Lion();
    
    //Les méthodes redéfinies
    void deplace(int i);
    char nom();
    std::string attaquer();
    
};

#endif // LION_H
