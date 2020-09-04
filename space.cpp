
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
using std::string;




Space* Space::getNorth() {
	return north;
}

Space* Space::getSouth() {
	return south;
}

Space* Space::getEast() {
	return east;
}

Space* Space::getWest() {
	return west;
}


std::string Space::getName() {

	return spaceName;
}

void Space::setDirections(Space* n,Space* s, Space* w,Space*  e) {

	this->north =  n;
	this->south = s;
	this->east = e;
	this->west = w;
}

