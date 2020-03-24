#include "desktop.h"
#include "options.h"

void Desktop:: add_option(Options& option){
	options.push_back(&option);	
}
double Desktop:: price(){
	double _price = 0.00;
	for(auto& p : options) {
		_price+=(p->cost());
	}	
	return _price;
}
std::ostream& operator <<(std::ostream& ost, Desktop& desktop){
	return ost<<std::to_string(desktop.price());
}

