//
//  Pierre.cpp
//  Survivor
//
//  Created by Willis Pinaud on 18/09/2015.
//  Copyright © 2015 Willis Pinaud. All rights reserved.
//

#include "Pierre.hpp"

Pierre::Pierre(){
    x = rand()%82;
    y = rand()%82;
}

void Pierre::deplace(int i){
}

char Pierre::nom(){
    char a= 'R';
    return a;
}

std::string Pierre::attaquer(){
    return "PIERRE";
}

Pierre::~Pierre(){

}
