
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

#include <iostream>
#include <memory>
#include "space.hpp"
#include "armory.hpp"


 Armory::Armory(){
	spaceName = "Armory";
	offerItem = true;
	crystalOn = false;
	doorOpen = false;
	needKey = true;
	visited = false;
	fightOn = false;
	spaceId = 3;
	keycardNum = 3;
}

 Armory::~Armory(){
	
	this->north = NULL;
	this->south = NULL;
	this->east = NULL;
	this->west = NULL;
	
	
}
