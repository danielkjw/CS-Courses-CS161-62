/*********************************************************************
** Author: Daniel Kim
CS 162: Final Project

space header file (parent class) to all Spaces

******************************************/
#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <iostream>
#include <cstdlib>

#include "space.hpp"


using std::cin;
using std::cout;
using std::string;
using std::endl;
using std::vector;




class CommandRoom : public Space{


	public:
		
		CommandRoom();
		~CommandRoom();
};

#endif
