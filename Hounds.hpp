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
* creature class (abstract_)
* Vampire
* Hounds
* Blue men
* Medusa
* Harry POtter


******************************************/
#ifndef Hounds_HPP
#define Hounds_HPP
#include <string>
#include <iostream>
#include <iomanip>
#include "character.hpp"


using std::string;

class Hounds : public Character{
    
    public:
        Hounds();
        ~Hounds(); 
        int attack();
        int defend(int attackVal);
        void revive();
};

#endif
