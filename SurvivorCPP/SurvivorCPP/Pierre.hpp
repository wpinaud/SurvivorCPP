//
//  Pierre.h
//  Survivor
//
//  Created by Willis Pinaud on 18/09/2015.
//  Copyright © 2015 Willis Pinaud. All rights reserved.
//

#ifndef Pierre_hpp
#define Pierre_hpp

#include <stdio.h>
#include <string>
#include "Animal.hpp"

class Pierre : public Animal{
    
public:
    Pierre();
    char nom();
    void deplace(int i);
    std::string attaquer();
    
};

#endif /* Pierre_hpp */
