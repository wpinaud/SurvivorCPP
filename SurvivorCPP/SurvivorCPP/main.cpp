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

void affiche (int TAILLEJEU, vector<Animal*> Animaux);
Animal* combattre(Animal *animal1, Animal *animal2, bool verbose); //Comment mettre une valeur par defaut ??

void creeTous(int nb_lion, int nb_ours, int nb_loup, int nb_pierre, vector<Animal*> &Animaux);
void deplacerTous(vector<Animal*> Animaux, int i);
void combattreTous(vector<Animal*> &Animaux);



int main(int argc, const char * argv[]) {

    //Trouver un moyen de stocker les animaux dans un vecteur

    //Réponse : vector<Animal*> Animaux;
    vector<Animal*> Animaux;
    creeTous(100, 100, 100, 100, Animaux);

    int TAILLEJEU = 82;
    
    affiche (TAILLEJEU, Animaux);
    

    for (int i=0; i<100; i++){
        
        deplacerTous(Animaux, i);
        combattreTous(Animaux);
        affiche (TAILLEJEU, Animaux);


    }
    return 0;
}


void affiche (int TAILLEJEU, vector<Animal*> Animaux){
    string plat[82][82];
    int i;
    int j;
    for (int unsigned u=0; u<Animaux.size(); u++){
        plat[Animaux[u]->getX()][Animaux[u]->getY()] = Animaux[u]->nom();
    }
    for (i=0; i<TAILLEJEU; i++){
        for (j=0; j<TAILLEJEU; j++){
            cout << plat[i][j]<< ".";
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
            vainqueur = animal1;
            delete animal2;
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


void creeTous(int nb_lion, int nb_ours, int nb_loup, int nb_pierre, vector<Animal*> &Animaux){

    for (int i = 0; i<=nb_lion; i++){
        Animaux.push_back(new Lion);
    }
    for (int i = 0; i<=nb_ours; i++){
        Animaux.push_back(new Ours);
    }
    for (int i = 0; i<=nb_loup; i++){
        Animaux.push_back(new DarkLoup);
    }
    for (int i = 0; i<=nb_pierre; i++){
        Animaux.push_back(new Pierre);
    }
}


void deplacerTous(vector<Animal*> Animaux, int i){
    for (int i = 0; i<=Animaux.size(); i++) {
        Animaux[0]->deplace(i);
    }
}

void combattreTous(vector<Animal*> &Animaux){
    for (int i = 0; i<Animaux.size(); i++) {
        for (int j = i+1; j<Animaux.size(); j++) {
            if (Animaux[i]->getX()==Animaux[j]->getX()) {
                if (Animaux[i]->getY()==Animaux[j]->getY()) {
                    Animal* vainqueur = combattre(Animaux[i], Animaux[j], true);
                    
                    if (vainqueur == Animaux[i]) {
                        for(std::vector<Animal*>::iterator it = Animaux.begin(); it != Animaux.end(); it++)
                        {
                            if (*it == Animaux[j])
                            {
                                Animaux.erase(it);
                                break;  //it is now invalud must break!
                            }
                        }
                    }
                    else{
                        for(std::vector<Animal*>::iterator it = Animaux.begin(); it != Animaux.end(); it++)
                        {
                            if (*it == Animaux[i])
                            {
                                Animaux.erase(it);
                                break;  //it is now invalud must break!
                            }
                        }
                    }
                    
                }
            }
        }
    }

}

