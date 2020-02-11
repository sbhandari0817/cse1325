#ifndef __color_h
#define __color_h

#include <iostream>

//making color class

class color{
	public:
		color (int red, int green, int blue);
		color();
		std::string to_string();
		friend std::ostream &operator << (std::ostream &ost, const color &color);
		friend std::istream &operator >> (std::istream &ist, color &color);
	private:
	int _red;
	int _green;
	int _blue;
	bool _reset;
};
#endif 
