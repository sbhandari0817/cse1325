#include "desktop.h"

void Desktop:: add_option(Options& option){
	options.push_back(option);	
}
double Desktop:: price(){
	double _price = 0.00
	for(auto& p : options) {
		_price+=options._cost
	}	
	return _price;
}
std::operator &ostream(ostream&ost, Desktop& desktop){
	return<<ost<<Desktop.price();
}

