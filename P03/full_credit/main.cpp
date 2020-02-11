#include <iostream>
#include "color.h"


int main (){
	int red,green,blue;
	color firstpart{250,0,0};
	color reset{};
	std::cout<<firstpart<<"This sentence should be colorized in red"<<reset<<std::endl;
	std::cout<<"Enter color as (red, green, blue): ";
	color values{red, green, blue};
	std:: cin >> values;
	std::cout<< values << values.to_string() <<reset<< std::endl;
	//std::cout<<Test_ints.colorize(Test_ints.to_string())<<std::endl;
}
