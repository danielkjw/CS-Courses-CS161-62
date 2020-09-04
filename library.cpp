
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
#include "library.hpp"

using std::string;

Library::Library(){
	spaceName = "Library";
	offerItem = true;
	crystalOn = true;
	doorOpen = true;
	needKey = false;
	visited = false;
	fightOn = true;
	spaceId = 6;
}

Library::~Library(){
	this->north = NULL;
	this->south = NULL;
	this->east = NULL;
	this->west = NULL;	
	
}
