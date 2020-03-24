#ifndef __Order_h
#define __Order_h
#include "customer.h"
#include "desktop.h"

class Order{
	public:
		Order(Customer& customer);
		virtual ~Order();
		int add_product(Desktop& desktop);
		double price();
		friend std::ostream& operator<<(std::ostream& ost,  Order& order);
	private:
		Customer& _customer;
		std::vector <Desktop*> _products;
};

#endif 

