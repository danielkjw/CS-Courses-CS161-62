
/*********************************************************************
** Author: Daniel Kim
CS 162: Final Project

space header file (parent class) to all Spaces

Goal: make it out of the research facility alive.

Classes:
Thing
Character
Game

******************************************/

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <memory>
#include <algorithm>
#include "space.hpp"
#include "item.hpp"
using std::string;
using std::vector;
class Space;

class Character{
    protected:
    
        int strength; //strength (or hp)
        string type;
        int armor;
        int attackVal;
        int defenseVal;
        int attackDieNum;
        int attackDieSides;
        int defenseDieNum;
        int defenseDieSides;
        int damageVal;
        bool isDead = false;
        int numLives;

        vector<Item*> itemBag;
        Space* location;
        Space* next;

        int itemCount;
        int maxItems;
        int psionicStorm;
        int numCrystals;
        int armorykey;
        int prisonkey;
        int commandkey;
        friend class gameEngine;
    
    public:
        
        Character(); //constructor
        virtual ~Character(); //destructor
        virtual int attack() = 0; 
        virtual int defend(int attack) = 0;
        virtual void revive() = 0;

        int dieRollSum(int dieNum, int sides);
        bool checkDead();
        int getStrength();
        void setStrength(int strength);
        string getType();
        int getAttackVal();
        int getDefenseVal();
        int getDamageVal();
        int applyDamage(int damage);
	    void addItem(Item* item1);
	    void useItem();
	    void dropItem(int i);
	    void displayItems();
	    Space* getLocation();
};


#endif