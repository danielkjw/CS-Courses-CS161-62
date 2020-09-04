/*********************************************************************
** Author: Daniel Kim
** Date: 05/27/2017
*
** Description:
* 

******************************************/
#ifndef ECHO1_HPP
#define ECHO1_HPP
#include "character.hpp"
#include "space.hpp"
#include <string>
#include <iostream>
#include <iomanip>
#include <memory>

using std::string;
using std::vector;

class Echo1 : public Character{
    
    private:
    
        vector<std::shared_ptr<Item>> itemBag;
        std::shared_ptr<Space> location;
        std::shared_ptr<Space> next;

        int itemCount;
        int maxItems;
        int psionicStorm;
        int numCrystals;
        int armorykey;
        int prisonkey;
        int commandkey;

    public:
        Echo1();
        ~Echo1(); 
        int attack();
        int defend(int attackVal);
	    void addItem(std::shared_ptr<Item> item1);
	    int useItem();
	    void dropItem(int i);
	    void displayItems();
        void revive();
};

#endif
