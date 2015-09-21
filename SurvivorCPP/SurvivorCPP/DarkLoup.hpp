#ifndef DARKLOUP_H
#define DARKLOUP_H

#include <string>
#include "Animal.hpp"

class DarkLoup : public Animal
{
public:
    //Constructeur et destructeur
    DarkLoup();
    virtual ~DarkLoup();
    
    //Les méthodes redéfinies
    void deplace(int i);
    std::string attaquer();
    char nom();
    
    
};

#endif // DARKLOUP_H
