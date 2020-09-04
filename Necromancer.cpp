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
#include "gameEngine.hpp"
#include "character.hpp"
#include "Necromancer.hpp"

#include <random>
using std::string;

Necromancer::Necromancer(){
    
        armor = 0;
        strength = 5;
        type = "Necromancer";
        attackVal= 0;
        defenseVal = 0;
        attackDieNum = 2;
        attackDieSides= 6;
        defenseDieNum = 2;
        defenseDieSides = 6;
        damageVal = 0;
        numLives = 3;
}

Necromancer::~Necromancer(){
    
    
}

int Necromancer::attack(){
    
    attackVal = dieRollSum(this->attackDieNum,this->attackDieSides);
    return attackVal;
    
}

int Necromancer::defend(int attackVal){
    
    int damage = attackVal;
    defenseVal = dieRollSum(this->defenseDieNum,this->defenseDieSides) + this->armor;
    damage = damage - defenseVal;
    return damage;
    
}
    

void Necromancer::revive(){
    
    setStrength(12);
    this->numLives = 1;
    
    
}
