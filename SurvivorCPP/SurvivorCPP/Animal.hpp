/*
 * animaux.h
 *
 *  Created on: 18 sept. 2015
 *      Author: eleve
 */


#ifndef ANIMAUX_H_
#define ANIMAUX_H_
#include <iostream>
#include <vector>
using namespace std;

class Animal{
protected:
    int x;
    int y;
    bool aBouge;
    
public:
    virtual void deplace(int i)=0;
    virtual char nom()=0;
    virtual string attaquer()=0;
    
    int getX(){ return x;};
    int getY(){ return y;};
    bool getaBouge(){ return aBouge;};
    
    void suicide() { this->~Animal();};
};

class Coordonnees {
public:
    int x; // entre 0 et 82
    int y; // entre 0 et 82
};



typedef vector<Animal*> ma_case;




#endif /* ANIMAUX_H_ */
