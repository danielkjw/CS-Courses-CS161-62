
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
#include "cafeteria.hpp"

using std::string;

Cafeteria::Cafeteria(){
	spaceName = "Cafeteria";
	offerItem = true;
	crystalOn = false;
	doorOpen = true;
	needKey = false;
	visited = false;
	fightOn = true;
	spaceId = 5;
}

Cafeteria::~Cafeteria(){
	
	this->north = NULL;
	this->south = NULL;
	this->east = NULL;
	this->west = NULL;
}
