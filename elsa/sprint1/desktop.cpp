#include "desktop.h"


void Desktop:: add_option(Options& option){
	options.push_back(&option);	
}
double Desktop:: price(){
	double _price = 0.00;
	for(auto o : options) {
		_price+=(o->cost());
	}	
	return _price;
}
std::ostream& operator <<(std::ostream& ost,const Desktop& desktop){
	ost<<"Desktop includes";
	for (auto o: desktop.options) ost<<"\n "<<*o;
	return ost;
}

