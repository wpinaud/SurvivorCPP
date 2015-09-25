#include "DarkLoup.hpp"

DarkLoup::DarkLoup(){
    x = rand()%82;
    y = rand()%82;
}

void DarkLoup::deplace(int i){
    int t= i%82;

    if (t==0){y=(y+1)%82;}
    else {x=(x+1)%82;}; /* Méthode "stupide": on parcourt le terrain et on attaque aléatoirement */
    /*switch (t){
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
            break;*/ /* Méthode "intel": on fait le mouvement d'un ours et on joue principalement pierre
            }*/
}

char DarkLoup::nom(){
    char a= 'K';
    return a;
}

std::string DarkLoup::attaquer(){
    int i = rand()%3; // génère un nombre aléatoire entre 0 et 9
    std::string attaques[3];
    attaques[0]="CISEAU";
    attaques[1] = "PIERRE";
    attaques[2] = "FEUILLE";
    /*attaques[3] = "PIERRE";
    attaques[4] = "PIERRE";
    attaques[5] = "PIERRE";
    attaques[6] = "PIERRE";
    attaques[7] = "PIERRE";
    attaques[8] = "FEUILLE";
    attaques[9] = "FEUILLE";*/


    return attaques[i];
}

DarkLoup::~DarkLoup(){

}
