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
* Cyborg
* Blue men
* Medusa
* Harry POtter


******************************************/
#include<iostream>
#include <string>

#include "character.hpp"
#include "Cyborg.hpp"
#include <random>
using std::string;

Cyborg::Cyborg(){
    
        armor = 5;
        strength = 12;
        type = "Cyborg";
        this-> type = type;
        attackVal= 0;
        defenseVal = 0;
        attackDieNum = 2;
        attackDieSides= 6;
        defenseDieNum = 2;
        defenseDieSides = 6;
        damageVal = 0;
        numLives = 2;
}

Cyborg::~Cyborg(){
    
    
}

int Cyborg::attack(){
    
    attackVal = dieRollSum(this->attackDieNum,this->attackDieSides);
    return attackVal;
    
}

int Cyborg::defend(int attackVal){
    
    int damage = attackVal;
    defenseVal = dieRollSum(this->defenseDieNum,this->defenseDieSides) + this->armor;
    damage = damage - defenseVal;
    return damage;
    
}
    

void Cyborg::revive(){
    
    setStrength(12);
    this->numLives = 1;
    
    
}
