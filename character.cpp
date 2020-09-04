
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
#include<iostream>
#include <string>

#include "character.hpp"
#include <random>
#include <iomanip>
using std::string;
using std::setw;
using std::left;
using std::right;

std::random_device rdev; //use random device as seed
std::default_random_engine e{rdev()}; //seed random default engine with random device

Character::Character(){
    
    next = NULL;

}

Character::~Character(){
    
    
}

int Character::dieRollSum(int dieNum, int dsides){
    
    int rollResult1 = 0;
    int rollSum1 = 0;
    std::uniform_int_distribution<int> rollDist1(1,dsides); //use uniform (equal) distribution of 1 to dSides with e as default random engine.

    for(int i = 0; i < dieNum; i++){
        
        rollResult1=rollDist1(e); // random number uniformly distributed from 1 to dSides inclusive added to rollResult for as many die the object has
        std::cout << setw(2) << "  Roll #" << i << ": " << rollResult1 << ";  " << setw(2);
        rollSum1 +=rollResult1;
    }

    return rollSum1;
}

int Character::applyDamage(int damage){
    std::cout << setw(2)<<  this->type << " " <<  this->type << " has taken " << damage << " damage." << std::endl;
    if(damage > 0)
    {
        this->strength -= damage;
        if(this->strength <=0){
            
            this->numLives = 0;
            this->isDead = true;
            std::cout << "Strength: " <<  this->strength << " " << this->type << " " << this->type << " has fallen." << std::endl;
            return this->strength;
        }
        return this->strength;
    }
}

bool Character::checkDead(){
    
    if(strength == 0){
        
        this->isDead = true;
        return isDead;
        
    }
    else{
         this->isDead = false;
        return isDead;
    }
    
}


int Character::getStrength(){
    
    return strength;
    
}

void Character::setStrength(int strength){
    
    this->strength = strength;
    
}

int Character::getAttackVal(){
    
    return attackVal;
}

int Character::getDefenseVal(){
    
    return defenseVal;
}

int Character::getDamageVal(){
    
    return damageVal;
}

string Character::getType(){
    
    return this->type;
}


void Character::addItem(Item* items){

    if(itemCount < maxItems){
        std::cout << items->itemName  << " added" << std::endl;
        if(items->itemId == 2)
            this->prisonkey = 2;
        else if(items->itemId == 3)
            this->armorykey = 3;
        else if(items->itemId == 43)
            this->commandkey = 4;
        else if(items->itemId == 6)
            this->numCrystals++;
        }
       std::cout << items->itemName  << " added" << std::endl;
        itemBag.push_back(items);
        
    if(itemCount > maxItems){
        
        std::cout << "Your bag is full. Drop an item" << std::endl;
    }
}


void Character::useItem(){
    int choice;
    std::cout << "Choose item to use" << std::endl;
    displayItems();
    cin >> choice;
	cin.ignore();


	while ((choice < 0) || (choice > 7)) {

		std::cout << "Please enter the integer 1 through 3, only." << std::endl;
		std::cout << "Choice: " << std::endl;
		std::cin >> choice;
		std::cin.ignore();
	}
    int itemResult;
    if(choice < itemBag.size()||!itemBag.empty()){
            switch(itemBag[choice]->itemId){
                
                case 1:
                    break;
                case 2:
                    this->prisonkey = 2;
                    break;
                case 3:
                    this->prisonkey = 3;
                    break;
                case 4:
                    this->prisonkey = 4;
                    break;
                case 5:
                    std::cout <<"Healthy cup of milk to get the HP up" <<std::endl;
                    itemBag.erase(itemBag.begin() + choice);
                    break;
                case 6:
                    std::cout <<"Can't do anything with cyrstals but look at the shine" <<std::endl;
                    itemBag.erase(itemBag.begin() + choice);
                    break;
                default:
                    std::cout << "no item found " << std::endl;
                    break;
            }
    }
    }


	    
void Character::displayItems(){
    if(!itemBag.empty()){
    std::cout <<"------------------------------" << std::endl;
    std::cout <<"------------------------------" << std::endl;
    std::cout << "Items in your bag: " <<std::endl;
        for (int i = 0; i < itemBag.size()-1; i++ ){
            std::cout<< std::left <<  "[Slot " << i << "]: "<< itemBag[i]->itemName<< setw(9)  << " [Quantity: " << itemBag[i]->quant << "] "<< std::endl;
        }
    }
}


Space* Character::getLocation(){

        return location;
}