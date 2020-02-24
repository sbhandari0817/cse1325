#include "product.h"


Product:: Product (std:: string name, double cost): _name{name}, _cost{cost}, _quantity{0}{
	if (cost <= 0){
		throw std::runtime_error {"You should enter positive value of cost."};
	}
}
Product:: ~Product(){

}

void Product:: set_quantity (int quantity){
	if (quantity < 0){
		throw std:: runtime_error {"You should enter positive value for quantity."};	
	}	
	else 
		_quantity = quantity;
}

double Product:: price()const {
		
	}

std::ostream& operator<< (std::ostream& ost, const Product& product){
	if (product._quantity > 0){
		std::string output = product._name +" ("+ std::to_string(product._quantity)+ " @ " + std::to_string(product._cost) +")";
		ost << output;	
		return ost;
	}
}

