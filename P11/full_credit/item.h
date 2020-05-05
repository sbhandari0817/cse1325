#ifndef __ITEM_H
#define __ITEM_H

#include <iostream>
#include <string>
#include <cstddef> //use for size_t
class Item{
	public:
		Item(std::string name, double price);
		double cost();
	private:
		std::string _name;
		double _price;
	friend std::ostream &operator <<(std::ostream &ost, const Item &item);
	friend std::istream &operator >>(std::istream &ist, const Item &item);
};
#endif
