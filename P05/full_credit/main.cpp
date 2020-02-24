#include "product.h"
#include "taxfree.h"
#include "taxed.h"
#include <iomanip>
#include <vector>

int main() {
    std::vector<std::string> items{"Milk", "Bread", "Cheese", "Ice Cream","Cheetos", "Oreos"};
	std::vector<double> price{2.19, 1.99,0.99,4.95,2.29,2.99};
	const std::string menu = R"(
======================
 Welcome to the Store
======================
0) Milk ($2.19)
1) Bread($1.99)
2) Cheese($0.99)
3) Ice Cream ($4.95)
4) Cheetos ($2.29)
5) Oreos ($2.99)

)";
std::vector<int> cart;
std::vector<int> numbers;
int qua, Product_index;
 do {
 	int i = 0;
 	double total;
    std::cout << menu << '\n';
	std::cout<< "Enter quantity (0 to exit) and product index: ";
	std::cin >>qua;
	std::cin>>Product_index;
	numbers.push_back(qua);
	cart.push_back(Product_index);
	for (auto x: cart){
		if ( x < 3){
			try
			{
			Taxed p1(items[x],price[x]);
			p1.set_quantity(numbers[i]);
			total+= p1.price();
			i++;
			std::cout << p1 << std::endl; 
			}
			catch(std::runtime_error e)
			{
				std::cerr<<e.what()<<std::endl;
			}
			
			}
		else if (x >= 3 || x < 6){
			try{
			Taxfree p1(items[x], price[x]);
			p1.set_quantity(numbers[i]);
			i++;
			total+= p1.price();
			std::cout << p1 << std::endl; 
			}
			catch(std::runtime_error e)
			{
				std::cerr<<e.what()<<std::endl;
			}
			}
		else std::cout <<"Out of range or under range"<<std::endl;
	}
    std::cout<<std::fixed << std::setprecision(2);
	std::cout <<"Total Price is " << total << std::endl;
	}while (qua != 0);

}

