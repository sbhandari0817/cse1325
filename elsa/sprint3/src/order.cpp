#include "order.h"

Order::Order(Customer& customer) : _customer{new Customer(customer)} {}
Order::~Order() {}
int Order::add_product(Desktop& desktop) {_products.push_back(&desktop); return _products.size()-1;}
double Order::price() const {
    double pr = 0;
    for(auto p : _products) pr += p->price();
    return pr;
}
std::ostream& operator<<(std::ostream& ost, const Order& order) {
    ost << "Customer: " << order._customer;
    for(auto p : order._products) ost << "\n  " << *p;
    ost << "\nTotal price: $" << order.price();
    return ost;
}

void Order::save(std::ostream& ost){
    ost<<_customer << '\n';
	ost<<_products.size();
	for (auto p : _products)p->save(ost);
}

Order::Order(std::istream& ist){
     _customer = new Customer(ist);
    int size;
	ist >> size;
	ist.ignore(32767, '\n');
	int i;
	for (i = 0; i < size; i++){
		_products.push_back(new Desktop(ist));	
	} 	
}


