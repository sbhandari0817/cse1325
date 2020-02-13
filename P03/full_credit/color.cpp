#include <iostream>
#include "color.h"

color:: color (int red, int green, int blue):_red{red},_green{green},_blue{blue},_reset{false}{	
}
std::ostream &operator<<(std::ostream &ost, const color &color){
	if (color._reset)
	{
		ost << "\033[0m";
	}
	else{
		std::string Color_text = "\033[38;2;"+ std::to_string(color._red) +";" + std::to_string(color._green)+";"+std::to_string(color._blue)+"m";
		ost << Color_text;
	}
	return ost;
}
color::color ():_reset{true}{
}
std::string color::to_string(){
	return "("+std::to_string(_red) +"," + std::to_string(_green)+","+std::to_string(_blue)	+")";
}
std::istream &operator>>(std::istream &ist, color &color){
	char a, b, c, d;
	ist >>a>>color._red >> b >> color._green >> c >> color._blue >> d; 
	return ist;
}

