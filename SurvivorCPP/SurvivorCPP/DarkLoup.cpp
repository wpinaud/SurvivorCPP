#include "DarkLoup.hpp"

DarkLoup::DarkLoup(){
    x = rand()%82;
    y = rand()%82;
}

void DarkLoup::deplace(int i){
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
}

char DarkLoup::nom(){
    char a= 'K';
    return a;
}

std::string DarkLoup::attaquer(){
    int i = rand()%10; // génère un nombre aléatoire entre 0 et 9
    std::string attaques[10];
    attaques[0]="CISEAU";
    attaques[1] = "CISEAU";
    attaques[2] = "PIERRE";
    attaques[3] = "PIERRE";
    attaques[4] = "PIERRE";
    attaques[5] = "PIERRE";
    attaques[6] = "PIERRE";
    attaques[7] = "PIERRE";
    attaques[8] = "FEUILLE";
    attaques[9] = "FEUILLE";


    return attaques[i];
}

DarkLoup::~DarkLoup(){

}
