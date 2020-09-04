#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <iomanip>
using std::setw;
using std::left;

#include "gameEngine.hpp"



using std::make_shared;

gameEngine::gameEngine(){
	
	numCrystals = 0;
	
	e1 = new Echo1();
    p2= new Cyborg();
    p3= new Necromancer();
    p4= new Hounds();
    p5= new Necromancer();

	Item* item1= new Item(1,1,"Laser");
	Item* item2= new Item(2,1,"Prison keycard");
	Item* item3= new Item(3,1,"Armory Keycard");
	Item* item4= new Item(4,1,"CommandRoom Keycard");
	Item* item5= new Item(5,1,"Healthkit");
	Item* item6= new Item(6,1,"Crystal1");
	Item* item7= new Item(6,1,"Crystal2");

	Space* lab= new Lab();
	Space* armory= new Armory();
	Space* prison= new Prison();
	Space* cafeteria= new Cafeteria();
	Space* library= new Library();
	Space* commandroom= new CommandRoom();
	Space* h1= new Hall1();
	e1->addItem(item1);
 
    monsterQ.push(p2);
    monsterQ.push(p3);
    monsterQ.push(p4);
    monsterQ.push(p5);
    
    itemQ.push(item2);
    itemQ.push(item3);
    itemQ.push(item4);
    itemQ.push(item5);
    itemQ.push(item6);
    itemQ.push(item7);

    


	lab->setDirections(NULL, h1, NULL, NULL);
	h1->setDirections(lab, library, armory, cafeteria);
	armory->setDirections(NULL, NULL, NULL, h1);
	prison->setDirections(NULL, cafeteria, NULL, h1);
	cafeteria->setDirections(prison, commandroom, h1, NULL);
	commandroom->setDirections(cafeteria, NULL, NULL, NULL);
	library->setDirections(h1, NULL, NULL, NULL);
	
	
	e1->addItem(item1);
	(e1->location) = lab;
	
	gameOn = true;
    success =false;
	
	

}


gameEngine::~gameEngine(){

	
	
	delete e1;
    delete p2;
    delete p3;
    delete p4;
    delete p5;
    delete item1;
    delete item2;
    delete item3;
    delete item4;
    delete item5;
    delete item6;
    delete item7;

	delete lab;
	delete armory;
	delete prison;
	delete cafeteria;
	delete library;
	delete commandroom;
	delete h1;

	
	
    e1=NULL;
    p2=NULL;
    p3=NULL;
    p4=NULL;
    p5=NULL;
    item1=NULL;
    item2=NULL;
    item3=NULL;
    item4=NULL;
    item5=NULL;
    item6=NULL;
    item7=NULL;

	lab= NULL;
	armory= NULL;
	prison= NULL;
	cafeteria= NULL;
	library= NULL;
	commandroom= NULL;
	h1= NULL;

	 
}
void gameEngine::setLocation(){

	int choice;
	bool move = false;
    while(move==false){
	cout << "\n Choose to travel:" << std::endl;
	
	cout << "Currenty in :" << e1->location->spaceName <<std::endl;
	if(e1->location->north != NULL)
	cout << "North:" << e1->location->north->spaceName <<std::endl;
	if(e1->location->south != NULL)
	cout << " South:"<< e1->location->south->spaceName  <<std::endl;
	if(e1->location->east != NULL)
	cout << " East:"<< e1->location->east->spaceName  <<std::endl;
	if(e1->location->west != NULL)
	cout << " West:"<< e1->location->west->spaceName  <<std::endl;
	
	cout << "------------------" <<endl;
	cout << "1. Travel North" << std::endl;
	cout << "2. Travel South" << std::endl;
	cout << "3. Travel East" << std::endl;
	cout << "4. Travel West" << std::endl;
    cout << "-----------------" << std::endl;
    cout << "5. Display Item" <<std::endl;
	cin >> choice;
	cin.ignore();
		while ((choice < 1) || (choice > 5) || cin.fail() ) {

		std::cout << "Please enter the integer 1 through 4, only." << std::endl;
		std::cout << "Choice: " << std::endl;
		std::cin >> choice;
		std::cin.ignore();
	}
    switch(choice){
        case 1:
            (e1->next) = e1->location->north;
            break;
        case 2:
            e1->next = e1->location->south;
            break;
        case 3:
            e1->next= e1->location->east;
            break;
        case 4:
            e1->next= e1->location->west;
            break;
        case 5:
            e1->displayItems();
            break;
    }
    if((e1->next) == NULL){

            std::cout << "Can't go that way" << std::endl;
    }
    else if((e1->next)!=NULL){
        move = true;
        if(e1->next->needKey == true){
            std::cout<< "Choose the keycard from your item..." << std::endl;
            e1->useItem();
            if(e1->commandkey  == (e1->next->keycardNum)|| e1->armorykey  == (e1->next->keycardNum)|| e1->prisonkey == (e1->next->keycardNum)){
                std::cout << "The door opened " << e1->next->spaceName << std::endl;
                e1->location->needKey = false;
                e1->location = e1->next;
                std::cout << "Now entering..." << std::endl;
                std::cout << e1->location->spaceName << std::endl;
            }
            else{
                
                std::cout << "The door is locked use the key pad for " << e1->next->spaceName << std::endl;
            }
        } 
        else{
            e1->location = e1->next;
            e1->location->needKey = false;
            std::cout << "Now entering..." << std::endl;
            std::cout << e1->location->spaceName << std::endl;
            e1->next = NULL;
        }
    }

	
}

}

int gameEngine::playGame(){
    while(gameOn){

        while((e1->numCrystals) != 3){
     
        	std::cout << "Your mission is to find all the cyrstals(2) and stay alive" <<std::endl;
        	std::cout << "Head to the command room when you have collected the cyrstals"<<std::endl;
        	std::cout << std::endl;
        	std::cout << std::endl;
        	setLocation();
        	
        	if(e1->location->offerItem == true){
                this->offerItem();
        	    
        	    e1->displayItems();
        	    (e1->location->offerItem) = false;
        	}
        	if(e1->location->fightOn == true){
        	    std::cout << "What is that " << std::endl;
        	    fightMode();
        	    e1->location->fightOn = false;
        	    
        	}
        
        	if(((e1->location)->spaceId == 7) && (e1->numCrystals == 2)){
        	    
        	    std::cout << "You have all crystals! Let's get out of here" << std::endl;
        	    endGame(true);
        	    this->gameOn = false;
        	    break;
        	}
        	break;
        }
    }
        
    endGame(false);
    
    std::cout << "It's finally over. Let's head out! Good job echo!" <<std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
        	
    
    while(!itemQ.empty())
        itemQ.pop();
    while(!monsterQ.empty())
        monsterQ.pop();
        
	for(int i =0; i < (e1->itemBag).size(); i++){
	    delete e1->itemBag[i];
	}
	return 0;
}
void gameEngine::offerItem(){
	if(e1->location->offerItem == true){
	    Item* temp;
	    int choice;
	    std::cout << "Found items!" << std::endl;
	    
    
	    std::cout << "\n Put it in your bag?" << std::endl;
	    std::cout << "1. Yes" << std::endl;
	    std::cout << "2. No" << std::endl;
    
	    cin >> choice;
	    cin.ignore();
    
	    while ((choice < 1) || (choice > 2)) {
    
	    	std::cout << "Please enter the integer 1 through 3, only." << std::endl;
	    	std::cout << "Choice: " << std::endl;
	    	std::cin >> choice;
	    	std::cin.ignore();
	    }
	    if(choice ==1){
	                if(!itemQ.empty()){
	                temp = itemQ.front();
	                if(temp->itemId == 6)
	                    e1->numCrystals++;
	                std::cout << "Added Item: " << temp->itemName << std::endl;
	                e1->addItem(temp); //location 2
	                itemQ.pop();
	                temp=NULL;
	                }
	                if(!itemQ.empty()){
	                temp = itemQ.front();
	                    if(temp->itemId == 6)
	                        e1->numCrystals++;
	                std::cout << "Added Item: " << temp->itemName << std::endl;
	                e1->addItem(temp);
	                temp=NULL; //location 2
	                itemQ.pop();
	                }
	        }
	    }

}

/*std::string getDisplay(std::ifstream&);            //Gets file contents

int printScreen(int argc, char *argv[])
{

    std::ifstream Reader ("banner.txt");             //Open file

    std::string Art = getDisplay (Reader);       //Get file
    
    std::cout << Art << std::endl;               //Print it to the screen

    Reader.close ();                           //Close file

    return 0;
}



std::string getDisplay(std::ifstream& File){
    std::string Lines = "";        //All lines
    
    if (File)                      //Check if everything is good
    {
	while (File.good ())
	{
	    std::string TempLine;                  //Temp line
	    std::getline (File , TempLine);        //Get temp line
	    TempLine += "\n";                      //Add newline character
	    
	    Lines += TempLine;                     //Add newline
	}
	return Lines;
    }
    else                           //Return error
    {
	return "ERROR File does not exist.";
    }
}
*/





void gameEngine::fightMode(){
    
    if(!monsterQ.empty()){
        Character* s1;
        s1 = monsterQ.front();
    
    int counter, turns=0;
    int attack,defend, damageResult;
    std::uniform_int_distribution<int> rollDist2(1,2);

 
    stat1 = CONTINUE;
    stat2 = CONTINUE;
    
    int rollResult = rollDist2(d1); //e1 goes first when die roll = 1
    if(rollResult == 1){
        
        counter = 0;
        std::cout << "Echo1 attacked first!" << std::endl;
        
    }
    else{
        
        counter = 1;
        std::cout << "Monster attacked suddenly" << std::endl;
    }
    
    
    
    while(((e1->strength)>0) && ((s1->strength) >0)){
        std::cout << std::endl;

        if(counter % 2 == 0){
            
            std::cout << "Attack roll: " << std::endl;
            attack = e1->attack();
            std::cout<< "   Echo1 attacked " << s1->type << " with " << attack <<std::endl;
            std::cout << "Defend: " <<std::endl;
            defend = s1->defend(attack);
            damageResult = s1->applyDamage(defend);
            if(s1->getStrength()<= 0){

                e1Status = WON;
                p2->numLives--;
                std::cout << "Echo1 is victorious." << std::endl;
                e1->location->fightOn = false;
                
            }
            
        }
        else if(counter % 2 != 0){
            
            std::cout << "Attack: " <<std::endl;
            attack = s1->attack();
            std::cout<< s1->getType() << " attacked echo1 with " << attack << std::endl;
            std::cout << "Defend: ";
            defend = e1->defend(attack);
            damageResult = e1->applyDamage(defend);
            if(e1->getStrength() <= 0){
                
                std::cout << "Echo1 has fallen" << damageResult << " in strength" << std::endl;
				gameOn = false;
				e1->location->fightOn = false;
            }

        }
        
        turns++;
        counter++;
    }
    
    
    if(s1->numLives = 0){
        
        e1->location->fightOn = false;
    }
    monsterQ.pop();
    s1 = NULL;
    
    }
    else{
        
        std::cout << "no more monsters to fight!" << std::endl;
    }
} 

void gameEngine::endGame(bool gameOn){
	
	if(gameOn == false){
		
		std::cout << "Good job! You made it out successfully!" <<std::endl;
	}


}