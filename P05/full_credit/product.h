#ifndef __product_h
#define __product_h

#include <iostream>

class Product{
	public:
		Product(std::string name, double cost);
		virtual ~Product();
		void set_quantity (int quantity);
		virtual double price() const;
		friend std::ostream& operator<< (std::ostream& ost, const Product& product);
	protected:
		int _quantity;
		double _cost;
		std::string _name;	
};
std::ostream& operator << (std::ostream& ost, const Product& product);
#endif

