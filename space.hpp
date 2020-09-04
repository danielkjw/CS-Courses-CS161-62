/*********************************************************************
** Author: Daniel Kim
CS 162: Final Project

space header file (parent class) to all Spaces

******************************************/
#ifndef SPACE_HPP
#define SPACE_HPP

#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <memory>
#include "character.hpp"
#include "item.hpp"

class Character;
using std::cin;
using std::cout;
using std::string;
using std::endl;
using std::vector;


class Space {

	protected:
	
		Space* north;
		Space* south;
		Space* east;
		Space* west;
		Item* i1;
		Item* i2;

		
		bool offerItem;
		bool crystalOn;
		bool doorOpen;
		bool needKey;
		bool visited;
		bool fightOn;
		string spaceName;
		int spaceId;
		int keycardNum;
		bool crystalUse;
		friend class gameEngine;
	
	public:

		void setDirections(Space* n, Space* s, Space* w, Space* e);
		string getName();
		Space* getNorth();
		Space* getSouth();
		Space* getEast();
		Space* getWest();
	    void drawMap();

};

#endif
