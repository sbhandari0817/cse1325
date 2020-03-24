#ifndef __Options_h
#define __Options_h

#include <string>

class Options{
	public:
		Options (std::string name , double cost);
		virtual ~Options();
		double cost();
		std::string to_string();
		friend std::ostream& operator<<(std::ostream& ost,  Options& options);
	 protected:
	 	std::string _name;
	 	double _cost;
};

#endif
