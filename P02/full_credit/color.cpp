
#include <iostream>
#include "color.h"

color:: color (int red, int green, int blue):_red{red},_green{green},_blue{blue}{
	
}
std::string color::to_string(){
	return "("+std::to_string(_red) +"," + std::to_string(_green)+","+std::to_string(_blue)	+")";	
}

std::string color::colorize(std::string text){
	return "\033[38;2;"+ std::to_string(_red) +";" + std::to_string(_green)+";"+std::to_string(_blue)+"m"+text+"\033[0m";
}




