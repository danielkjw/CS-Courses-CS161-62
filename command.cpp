
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

#include "command.hpp"

using std::string;

CommandRoom::CommandRoom(){
	spaceName = "CommandRoom";
	offerItem = true;
	crystalOn = false;
	doorOpen = false;
	needKey = true;
	visited = false;
	fightOn = true;
	spaceId = 7;
	keycardNum = 4;
}

CommandRoom::~CommandRoom(){
	
	
}
