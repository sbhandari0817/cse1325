#include "store.h"

//
// Store
//
Store::Store(){}
Store::Store(std::istream& ist){
	int size;
	ist >> size;
	ist.ignore(32767, '\n');
	int i;
	for (i = 0; i < size; i++){
		customers.push_back(ist);	
	}
	ist >> size;
	ist.ignore(32767, '\n');
	for (i = 0; i < size; i++){
		options.push_back(new Options(ist));
	}
	ist >> size;
	ist.ignore(32767, '\n');
	for (i = 0; i < size; i++){
		desktops.push_back(ist);
	}
	ist >> size;
	ist.ignore(32767, '\n');
	for (i = 0; i < size; i++){
		orders.push_back(ist);
	}
}
void Store::save(std::ostream& ost){
	ost<<customers.size()<<'\n';
	for (auto c: customers)c.save(ost);
	ost<<options.size()<<'\n';
	for (auto o: options)o->save(ost);
	ost<<desktops.size()<<'\n';
	for (auto d: desktops)d.save(ost);
	ost << orders.size() << '\n';
	for (auto p: orders)p.save(ost);
}
void Store::add_customer(Customer& customer) {customers.push_back(customer);}
int Store::num_customers() {return customers.size();}
Customer& Store::customer(int index) {return customers.at(index);}

//
// Options
//
void Store::add_option(Options& option) {options.push_back(new Options{option});}
int Store::num_options() {return options.size();}
Options& Store::option(int index) {return *options.at(index);}

//
// Products
//
int Store::new_desktop() {
    desktops.push_back(Desktop{});
    return desktops.size()-1;
}
void Store::add_option(int option, int desktop) { // to desktop
    desktops[desktop].add_option(*options[option]);
}
int Store::num_desktops() {return desktops.size();}
Desktop& Store::desktop(int index) {return desktops[index];}

//
// Orders
//
int Store::new_order(int customer) {
    orders.push_back(Order{customers[customer]});
    return orders.size()-1;
}
    
void Store::add_desktop(int desktop, int order) { // to order
    orders[order].add_product(desktops[desktop]);
}
int Store::num_orders() {return orders.size();}
Order& Store::order(int index) {return orders[index];}
