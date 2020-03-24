#ifndef __Desktop_h
#define __Desktop_h
#include "vector"
#include "options.h"

class Desktop{
	public:
		void add_option(Options& option);
		double price();
		friend std::ostream& operator<<(std::ostream& ost, const Desktop& desktop);
	private:
		std::vector<Options*> options;

};

#endif 

