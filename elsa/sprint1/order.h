#ifndef __Order_h
#define __Order_h

class Order{
	public:
		Order(Customer& customer);
		virtual Order();
		int add_product(Desktop& desktop);
		double price();
		friend std::ostream& operator<<(std::ostream& ost, const Order& order);
	private:
		Customer& _customer;
		std::vector <Desktop*> _products;
};

#endif 

