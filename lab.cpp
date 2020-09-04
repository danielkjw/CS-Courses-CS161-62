
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
#include "gameEngine.hpp"
#include "lab.hpp"

using std::string;

Lab::Lab(){
	spaceName = "Lab";
	offerItem = true;
	crystalOn = true;
	doorOpen = false;
	needKey = false;
	visited = false;
	fightOn = true;
	spaceId = 2;
	
}

Lab::~Lab(){
	this->north = NULL;
	this->south = NULL;
	this->east = NULL;
	this->west = NULL;
	
}
