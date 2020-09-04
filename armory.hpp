/*********************************************************************
** Author: Daniel Kim
CS 162: Final Project

space header file (parent class) to all Spaces

******************************************/
#ifndef ARMORY_HPP
#define ARMORY_HPP


#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include "space.hpp"
using std::cin;
using std::cout;
using std::string;
using std::endl;


class Armory : public Space{


	public:
		
		Armory();
		~Armory();
};

#endif
