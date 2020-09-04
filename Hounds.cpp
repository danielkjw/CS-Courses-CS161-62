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
* Hounds
* Blue men
* Medusa
* Harry POtter


******************************************/
#include<iostream>
#include <string>

#include "character.hpp"
#include "space.hpp"
#include "Hounds.hpp"
#include <random>
#include "gameEngine.hpp"
using std::string;

Hounds::Hounds(){
    
        armor = 0;
        strength = 12;
        type = "Hounds";
        attackVal= 0;
        defenseVal = 0;
        attackDieNum = 6;
        attackDieSides= 1;
        defenseDieNum = 2;
        defenseDieSides = 6;
        damageVal = 0;
        numLives = 2;
}

Hounds::~Hounds(){
    
    
}

int Hounds::attack(){
    
    attackVal = dieRollSum(this->attackDieNum,this->attackDieSides);
    return attackVal;
    
}

int Hounds::defend(int attackVal){
    
    int damage = attackVal;
    defenseVal = dieRollSum(this->defenseDieNum,this->defenseDieSides) + this->armor;
    damage = damage - defenseVal;
    return damage;
    
}
    

void Hounds::revive(){
    
    setStrength(12);
    this->numLives = 1;
    
    
}
