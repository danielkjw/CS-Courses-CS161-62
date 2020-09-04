/*********************************************************************
** Author: Daniel Kim
CS 162: Final Project

space header file (parent class) to all Spaces

******************************************/
#ifndef CAFETERIA_HPP
#define CAFETERIA_HPP
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include "space.hpp"

using std::cin;
using std::cout;
using std::string;
using std::endl;
using std::vector;



class Cafeteria : public Space{


	public:
		
		Cafeteria();
		~Cafeteria();
};

#endif
