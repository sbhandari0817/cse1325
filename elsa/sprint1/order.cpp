#include "order.h"
#include "customer.h"
#include "desktop.h"

Order::Order(Customer& customer):_customer{customer}{

}
Order::~Order(){
}
int Order::add_product(Desktop& desktop){
	_products.push_back(&desktop);
	return _products.size()-1;
}
double Order::price(){
	double _price = 0.00;
	for (auto x: _products){
		_price += x->price();
	}
	return _price;
}
 std::ostream& operator<<(std::ostream& ost, Order& order){
 	ost << std::to_string(order.price());
 	return ost;
 }
