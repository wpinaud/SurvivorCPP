//
//  main.cpp
//  Survivor
//
//  Created by Willis Pinaud & Eric Lalevée on 18/09/2015.
//  Copyright © 2015 Willis Pinaud & Eric Lalevée. All rights reserved.
//

#include <iostream>
#include "Lion.hpp"
#include "Ours.hpp"
#include "Pierre.hpp"
#include "DarkLoup.hpp"
using namespace std;

void affiche (int TAILLEJEU);
Animal* combattre(Animal *animal1, Animal *animal2, bool verbose); //Comment mettre une valeur par defaut ??
void creeTous(int nb_lion, int nb_ours, int nb_loup, int nb_pierre, vector<Animal>* Animaux);
void deplacerTous(vector<Animal>);


int main(int argc, const char * argv[]) {
    
    //Faire fonction pour créer tous les animaux sur le tableau
    
    Animal *lion1 = new Lion();
    Animal *ours1 = new Ours();
    Animal *pierre1 = new Pierre();
    Animal *loup1 = new DarkLoup();
    
    vector<Animal> *Animaux;
    creeTous(10, 10, 10, 10, Animaux);
    
    int TAILLEJEU = 82;
    affiche (TAILLEJEU);
    for (int i=0; i<1; i++){
        
        //Trouver un moyen de stocker les animaux dans un vecteur
        
        //Lors de la victoire d'un animal supprimer le perdant du vecteur ou trouver un moyen de le faire directement avec le destructeur
        
        //Faire fonction déplacer tous
        
        //Faire fonction pour faire combattre tous
        
        //Faire fonction pour afficher le tableau
        
        Animal* vainqueur1 = combattre(lion1, ours1, true);
        
        Animal* vainqueur2 = combattre(vainqueur1, pierre1, true);

        Animal* vainqueur3 = combattre(vainqueur2, loup1, true);
    }
    return 0;
}


void affiche (int TAILLEJEU){
    string plat[82][82];
    int i;
    int j;
    for (i=0; i<TAILLEJEU; i++){
        for (j=0; j<TAILLEJEU; j++){
            cout << plat[i][j]<< "";
        }
        cout << endl;
    }
}

Animal* combattre(Animal* animal1, Animal* animal2, bool verbose){
    Animal* vainqueur;
    
    string attaque1 = animal1->attaquer();
    string attaque2 = animal2->attaquer();
    
    if (verbose) {
        cout << animal1->nom() << " avec "<< attaque1 << " contre " << animal2->nom()<<" avec "<< attaque2 << endl;
    }
    
    if (attaque1=="FEUILLE"){
        if (attaque2=="PIERRE") {
            delete animal2;
            vainqueur = animal1;
        }
        else if (attaque2=="FEUILLE") {
            vainqueur = ( rand()%2 ? animal1 : animal2 );
            ( vainqueur == animal1 ? delete animal2 : delete animal1 );
        }
        else if (attaque2=="CISEAU"){
            delete animal1;
            vainqueur = animal2;
        }
    }
    else if (attaque1=="PIERRE"){
        if (attaque2=="PIERRE") {
            vainqueur = ( rand()%2 ? animal1 : animal2 );
            ( vainqueur == animal1 ? delete animal2 : delete animal1 );
        }
        else if (attaque2=="FEUILLE") {
            delete animal1;
            vainqueur = animal2;
        }
        else if (attaque2=="CISEAU"){
            delete animal2;
            vainqueur = animal1;
        }
    }
    else if (attaque1=="CISEAU"){
        if (attaque2=="PIERRE") {
            delete animal1;
            vainqueur = animal2;
        }
        else if (attaque2=="FEUILLE") {
            delete animal2;
            vainqueur = animal1;
        }
        else if (attaque2=="CISEAU"){
            vainqueur = ( rand()%2 ? animal1 : animal2 );
            ( vainqueur == animal1 ? delete animal2 : delete animal1 );
        }
    }
    
    if (verbose) {
        cout << "  Vainqueur round: "<< vainqueur->nom() << endl;
    }
    return vainqueur;
}

void creeTous(int nb_lion, int nb_ours, int nb_loup, int nb_pierre, vector<Animal>& Animaux){
    
    for (int i = 0; i<=nb_lion; i++){
        Animaux.push_back(*new Lion);
    }
    for (int i = 0; i<=nb_ours; i++){
        Animaux.push_back(*new Ours);
    }
    for (int i = 0; i<=nb_loup; i++){
        Animaux.push_back(*new DarkLoup);
    }
    for (int i = 0; i<=nb_pierre; i++){
        Animaux.push_back(*new Pierre);
    }
    
}

void deplacerTous(vector<Animal>){
    for (int i = 0; i<=sizeof(vector<Animal>); i++) {
        // vector<Animal>[i].deplacer(); ??? Comment acceder à la fonction déplacer de l'élément d'un vector
    }
}
