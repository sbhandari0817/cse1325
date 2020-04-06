#ifndef __DESKTOP_H
#define __DESKTOP_H

#include "options.h"
#include <vector>

class Desktop{
	public:
		Desktop();
		void add_option(Options& option);
		double price();
		void save (std::ostream& ost);
		Desktop (std::istream& ist);
		friend std::ostream& operator<<(std::ostream& ost, const Desktop& desktop);
	private:
		std::vector<Options*> options;

};

#endif 

