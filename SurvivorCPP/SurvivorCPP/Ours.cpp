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
            y = (y+1)%82;
            break;

        case 1: //droite
            x= (x+1)%82;
            break;

        case 2: //haut
            y= (y-1)%82;
            break;

        case 3: //gauche
            x= (y-1)%82;
            break;
    }

    aBouge = true;
}

char Ours::nom(){
    char a= 'B';
    return a;
}

std::string Ours::attaquer(){
    return "FEUILLE";
}



