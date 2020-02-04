#include <iostream>
#include "color.h"

int main (){
	int red,green,blue;
	color firstpart{250,0,0};
	std::cout<<firstpart.colorize("Rose is Red")<<std::endl;
	std::cout<<"Enter the red green and blue ints"<<std::endl;
	std::cin >>red>>green>>blue;
	color Test_ints{red,green,blue};
	std::cout<<Test_ints.colorize(Test_ints.to_string())<<std::endl;
}

