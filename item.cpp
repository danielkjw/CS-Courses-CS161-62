
#include "space.hpp"
#include "item.hpp"


 Item::Item(int id, int num, std::string name){
    itemId = id;
    quant = num;
    this->itemName = name;
 }
 
 Item::~Item(){
     
     
 }