
#include <iostream>
#include "color.h"

color:: color (int red, int green, int blue):_red{red},_green{green},_blue{blue}{
	
}
std::string color::to_string(){
	return "("+std::to_string(_red) +"," + std::to_string(_green)+","+std::to_string(_blue)	+":"+std::to_string(color::magnitude())+ ")"+std::to_string(color::magnitude()) ;
	
}
std::string color::colorize(std::string text){
	return "\033[38;2;"+ std::to_string(_red) +";" + std::to_string(_green)+";"+std::to_string(_blue)+"m"+text+"\033[0m";
}
int color:: magnitude(){
	return (0.21*_red+0.72*_green + 0.07*_blue);
}
int color::compare(color rhs){
	if (this->magnitude()< rhs.magnitude()) return -1;
	else if (this ->magnitude() > rhs.magnitude()) return 1;
	else return 0;
}




