/*********************************************************************
** Author: Daniel Kim
** Date: 05/27/2017
*
** Description:
* Project 4 (continuation of project 3)

-Option for user to enter number of fighters both players will use. (limit 20 per team)
-User can enter the type of creatures and fighter names. 
-Head of each lineup fight in the same way they fight in project 3.
-The winner gets put at the back of her/his team’s lineup; the loser goes to the container for those who lost 
-Losers Stack: loser pile have the last loser at the top and the first loser at the bottom.
-Winners have restored some percentage of the damage when they get back in line.
-After each round, display of which type of creatures fought and which won on screen
-At the end of the tournament (when one team or both run out of fighters in the lineup), program will display final total points for each team (you can determine how to score each round of fight, for example, winner team +2, loser team -1, tie +1).
-Display which team won the tournament.
-Option at the end of the tournament to display the contents of the loser pile, i.e. print them out in order with the loser of the first round displayed last.



******************************************/
#include <iostream>
#include <string>

#include "character.hpp"
#include "Echo1.hpp"
#include <random>
#include <iomanip>
#include <memory>
#include <vector>
#include <algorithm>
using std::setw;
using std::left;
using std::string;

Echo1::Echo1(){
    
        strength = 100;
        type = "Echo1";
        attackVal= 0;
        defenseVal = 2;
        attackDieNum = 2;
        attackDieSides= 6;
        defenseDieNum = 2;
        defenseDieSides = 6;
        damageVal = 0;
        numLives = 1;
        psionicStorm = 2;
        numCrystals = 0;
        itemCount = 0;
        maxItems = 4;
        
        armorykey = 0;
        prisonkey= 0;
        commandkey= 0;
}

Echo1::~Echo1(){
    
    
}

int Echo1::attack(){
	int answer;

	std::cout << "\n Choose your attack!:" << std::endl;
	std::cout << "1. Use Laser" << std::endl;
	std::cout << "2. Psionic Storm" << std::endl;
   std::cin >> answer;
    while(std::cin.fail() || ((answer == 1 || answer == 2 || answer == 3 || answer == 4 || answer == 5)==false)){
            if(std::cin.fail()){
                    std::cout << "Please enter an integer of 1 or 2" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(256,'\n');// ignores 256 characters or until \n is read
                    std::cin >> answer;
            }
            else{
                    std::cout << "Please enter 1 or 2" << std::endl;
                    std::cin.ignore(256,'\n');// ignores 256 characters or until \n is read
                    std::cin >> answer;
            }
    }

    if(answer == 1){
        
        //"1. Use Laser" 
        std::cout << "Let's toast the monster with this laser!" << std::endl;
        
        attackDieNum = 1;
        attackDieSides = 6;
        attackVal = dieRollSum(attackDieNum, attackDieSides);
    }
    else if(answer == 2){
        if(psionicStorm > 0){
        std::cout << "You left me with no choice. Psionic Storm." << std::endl;
        std::cout << "Whew... I have " << this -> psionicStorm << " left" <<  std::endl;
        
        attackDieNum = 100;
        attackDieSides = 2;
        attackVal = dieRollSum(attackDieNum, attackDieSides);
        }
    }
        return attackVal;

}
	


int Echo1::defend(int attackVal){
    
    int damage = attackVal;
    defenseVal = dieRollSum(this->defenseDieNum,this->defenseDieSides) + this->armor;
    damage = damage - defenseVal;
    return damage;
}
    



void Echo1::revive(){
    
    strength=1000;
}

