#ifndef ITEM_HPP
#define ITEM_HPP



class Item{
    
    public:
        int quant;
		char itemId;
		std::string itemName;
		Item(int id, int num, std::string name);
		~Item();

};

#endif