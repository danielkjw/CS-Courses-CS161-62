
#ifndef NECROMANCER_HPP
#define NECROMANCER_HPP
#include "character.hpp"

#include <string>
#include <iostream>
#include <iomanip>

using std::string;
class Character;


class Necromancer : public Character{
    
    public:
        Necromancer();
        ~Necromancer(); 
        int attack();
        int defend(int attackVal);
        void revive();
};

#endif
