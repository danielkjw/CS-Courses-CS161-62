/*********************************************************************
** Author: Daniel Kim
CS 162: Final Project

space header file (parent class) to all Spaces

******************************************/

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

#ifndef PRISON_HPP
#define PRISON_HPP


class Prison : public Space{


	public:
		
		Prison();
		~Prison();
};

#endif
