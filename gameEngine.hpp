#ifndef GAMEENGINE_HPP
#define GAMEENGINE_HPP


#include <iostream>
#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
#include <memory>
#include <random>
#include "item.hpp"
#include "space.hpp"
#include "character.hpp"
#include "lab.hpp"
#include "hall1.hpp"
#include "armory.hpp"
#include "prison.hpp"
#include "cafeteria.hpp"
#include "command.hpp"
#include "library.hpp"
#include "Cyborg.hpp"
#include "Echo1.hpp"
#include "Necromancer.hpp"
#include "Hounds.hpp"
#include <queue>
using namespace std;

class gameEngine{
    
    
    private:
        int numCrystals;
        enum Status {CONTINUE, WON, LOST};//{CONTINUE = 0, WON = 1, LOST = 2}
        int stat1;
        int stat2;
        Status e1Status;
        Status s1Status;
        double e1Wins;
        double s1Wins;
        double numRounds;
        double currRound;
        bool gameOn;
        bool success;
        bool e1Move;
        Character* p1;
        queue<Character*> monsterQ;
        queue<Item*> itemQ;
        //float totalRounds;

        std::random_device rdev; //use random device as seed
        std::default_random_engine d1{rdev()}; 
        Character* e1;
        Character* p2;
        Character* p3;
        Character* p4;
        Character* p5;
        Item* item1;
        Item* item2;
        Item* item3;
        Item* item4;
        Item* item5;
        Item* item6;
        Item* item7;

        Space* infirmary;
	    Space* lab;
	    Space* armory;
	    Space* prison;
	    Space* cafe;
	    Space* library;
	    Space* cafeteria;
	    Space* commandroom;
	    Space* h1;
	    Space*  h2;
    public:
        gameEngine();
        ~gameEngine();
        std::string getFileContents(std::ifstream&);

        char attackMenu();
        void setLocation();
       
        char itemMenu();
        void offerItem();
        void fightMode();
        int playGame();
        void endGame(bool game);
};

#endif