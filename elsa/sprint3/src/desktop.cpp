#include "desktop.h"

Desktop::Desktop(){}
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
void Desktop::save(std::ostream& ost){
	ost<<options.size() << '\n';
	for (auto o: options)o->save(ost);
}
Desktop::Desktop(std::istream& ist){
	int size;
	ist >> size;
	ist.ignore(32767, '\n');
	int i;
	for (i = 0; i < size; i++){
		options.push_back(new Options{ist});	
	}
}


