#include "cart.h"
#include "item.h"
int main(){
	std::string name;
	double price;
	Cart kroger{"Santosh"};
	Item item{name, price };
	std::cout<<"Enter product names and price (e.g., "English peas 0.79"):"<<std::endl
	std::cin >>item;
	std::cout<<kroger;
}
