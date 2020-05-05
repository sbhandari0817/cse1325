#include "item.h"

Item::Item(std::string name, double price):_name{name},_price(price){
}
double Item::cost(){
	return _price;
}
std::ostream &operator << (std::ostream &ost , const Item& item){
	ost<<"$\t"<<std::to_string(item._price)<<"\t"<<item._name;
	return ost;
}
std::istream &operator >> (std::istream &ist, const Item& item){
	std::string product;
	ist>>product;
	std::size_t lastSpace = product.find_last_of(" ");
	item._name = product.substr(0,lastSpace);
	item._price = std::stod(product.substr(lastSpace+1));
	return ist;
}



