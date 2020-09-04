
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
#include "gameEngine.hpp"
#include "prison.hpp"

using std::string;

Prison::Prison(){
	spaceName = "Prison";
	offerItem = true;
	crystalOn = true;
	doorOpen = false;
	needKey = true;
	visited = false;
	fightOn = true;
	spaceId = 4;
	keycardNum = 2;
	
}

Prison::~Prison(){
	this->north = NULL;
	this->south = NULL;
	this->east = NULL;
	this->west = NULL;
}
