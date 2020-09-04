/*********************************************************************
** Author: Daniel Kim
CS 162: Final Project

space header file (parent class) to all Spaces

******************************************/



#ifndef LIBRARY_HPP
#define LIBRARY_HPP


#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include "space.hpp"
#include "gameEngine.hpp"
using std::cin;
using std::cout;
using std::string;
using std::endl;
using std::vector;

class Library : public Space{


	public:
		
		Library();
		~Library();
};

#endif
