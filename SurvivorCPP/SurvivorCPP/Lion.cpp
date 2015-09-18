#include "Lion.hpp"

Lion::Lion() : Animal(){
    this->x = 0;
    this->y = 0;
}

void Lion::deplace(int i){
    //mouvement d'une case vers le bas
    if (i%2==0){
        y=(y+1)%82;
    }
    //mouvement d'une case sur la droite
    else {
        x=(x+1)%82;
    }
}

char Lion::nom(){
    char a= 'L';
    return a;
}

std::string Lion::attaquer(){
    //rsrand (time(NULL));
    int i = (rand()%2)*2; // gÈnËre un nombre alÈatoire (0 ou 2)
    
    std::string attaques[3];
    attaques[0]="CISEAU";
    attaques[1] = "PIERRE";
    attaques[2] = "FEUILLE";
    
    return attaques[i];
}