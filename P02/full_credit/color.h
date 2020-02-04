#ifndef __color_h
#define __color_h


#include <iostream>

//making color class

class color{
	public:
		color (int red, int green, int blue);
		std::string to_string();
		std::string colorize(std::string text);
	private:
	int _red;
	int _green;
	int _blue;
};
#endif 
