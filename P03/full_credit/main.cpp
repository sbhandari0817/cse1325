#include <iostream>
#include "color.h"


int main (){
	int red,green,blue;
	color firstpart{250,0,0};
	color secondpart{0,250,0};
	color thirdpart {0,0,250};
	color reset{};
	std::cout<<firstpart<<"This sentence should be colorized in red"<<reset<<std::endl;
	std::cout<<secondpart<<"This sentence should be colorized in green"<<reset<<std::endl;
	std::cout<<thirdpart<<"This sentence should be colorized in blue"<<reset<<std::endl;
	std::cout<<"Enter color as (red, green, blue): ";
	color values{red, green, blue};
	std:: cin >> values;
	std::cout<< values << values.to_string() <<reset<< std::endl;
}
