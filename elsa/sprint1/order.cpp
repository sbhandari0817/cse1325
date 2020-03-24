#include "order.h"

Order::Order(Customer& customer):_customer{customer}{

}
Order::virtual Order(){
}
int Order::add_product(Desktop& desktop){
	_product.push_back(&desktop);
	return _product.size()-1;
}
double Order::price(){
	double price = 0.00;
	for (auto x: _product){
		price += x._price();
	}
	return price;
}
 std::ostream& operator<<(std::ostream& ost, const Order& order){
 	ost<<"Toatl product: "<<order.add_price()<<"Total Price: "<<order.price();
 }
