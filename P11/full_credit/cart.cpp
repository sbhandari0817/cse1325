#include "cart.h"

Cart::Cart(std::string customer):_customer{customer}{ }
Cart::~Cart(){

}
Cart::Cart(const Cart &cart):_customer{cart._customer},_items{}{
	for (auto &p: _items){
		_items.push_back(new Item(*p));
	}
}
Cart& Cart::operator=(const Cart& cart){
 	if (this != &cart){
 		_customer = cart._customer;
 		for (auto p: (cart._items)){
 			_items.push_back(new Item(*p));
 		}
 	}
}
void Cart::add_item(Item &item){
	_items.push_back(new Item{item});
}
double Cart::cost(){
	double Total = 0.00;
	for (auto p: _items){
		Total += p->cost();
	}
}
std::vector <Item*>::iterator Cart::begin(){
	return _items.begin();
}
std::vector<Item*>::iterator Cart::end(){
	return _items.end()-1;
}
