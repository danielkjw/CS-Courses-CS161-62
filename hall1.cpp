
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
#include "hall1.hpp"

using std::string;

Hall1::Hall1(){
	spaceName = "Hall-1";
	offerItem = true;
	crystalOn = true;
	doorOpen = true;
	needKey = false;
	visited = false;
	fightOn = false;
	spaceId = 9;
}

Hall1::~Hall1(){
	this->north = NULL;
	this->south = NULL;
	this->east = NULL;
	this->west = NULL;
	
}
