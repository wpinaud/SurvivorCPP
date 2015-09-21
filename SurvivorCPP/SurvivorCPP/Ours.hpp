#ifndef Ours_h
#define Ours_h
#include "Animal.hpp"
#include <stdio.h>
#include <string>

class Ours : public Animal
{
private:
    int pas;
    
public:
    //Constructeur et destructeur
    Ours();
    virtual ~Ours();
    
    //Les méthodes redéfinies
    void deplace(int i);
    char nom();
    std::string attaquer();
};

#endif /* Pierre_hpp */
