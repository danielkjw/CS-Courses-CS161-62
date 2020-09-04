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
#ifndef Hall1_HPP
#define Hall1_HPP


class Hall1 : public Space{


	public:
		
		Hall1();
		~Hall1();
};

#endif
