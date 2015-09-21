#include "Ours.hpp"

Ours::Ours(){
    y=rand()%82;
    x=rand()%82;
}

Ours::~Ours(){
    
}

void Ours::deplace(int i){
    int t= i%4;
    
    switch (t){
        case 0: //bas
            y++;
            break;
            
        case 1: //droite
            x++;
            break;
            
        case 2: //haut
            y--;
            break;
            
        case 3: //gauche
            x--;
            break;
    }
    
    aBouge = true;
}

char Ours::nom(){
    char a= 'R';
    return a;
}

std::string Ours::attaquer(){
    return "FEUILLE";
}



