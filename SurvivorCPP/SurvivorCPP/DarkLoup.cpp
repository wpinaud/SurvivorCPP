#include "DarkLoup.hpp"

DarkLoup::DarkLoup()
{
    x = rand()%82;
    y = rand()%82;
}

void DarkLoup::deplace(int i){
    
}

char DarkLoup::nom(){
    char a= 'K';
    return a;
}

std::string DarkLoup::attaquer(){
    return "PIERRE";
}

DarkLoup::~DarkLoup(){
    
}