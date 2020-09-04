/*********************************************************************
** Author: Daniel Kim
** Date: 05/16/2017
*
** Description:
* Project 3: Fantasy Combat Game
* Die rolls: attack and defense
* attack and type will depend the type of die and 
* type of die depends on the class type(character)
* 
* Structure: 
* Character class (abstract_)
* Vampire
* Cyborg
* Blue men
* Medusa
* Harry POtter


******************************************/
#ifndef CYBORG_HPP
#define CYBORG_HPP

#include "character.hpp"
#include <string>
#include <iostream>
#include <iomanip>

using std::string;

class Cyborg : public Character{
    
    public:
        Cyborg();
        ~Cyborg(); 
        int attack();
        int defend(int attackVal);
        void revive();
};

#endif
