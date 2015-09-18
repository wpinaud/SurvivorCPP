//
//  main.cpp
//  Survivor
//
//  Created by Willis Pinaud & Eric Lalevée on 18/09/2015.
//  Copyright © 2015 Willis Pinaud & Eric Lalevée. All rights reserved.
//

#include <iostream>
#include "Lion.hpp"
using namespace std;

void affiche (int TAILLEJEU);


int main(int argc, const char * argv[]) {
    
    Lion lion1;
    
    
    int TAILLEJEU = 82;
    affiche (TAILLEJEU);
    for (int i=0; i<1000; i++){
        lion1.deplace(i);
        cout << lion1.getX() << "et" << lion1.getY() << endl;
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
