#ifndef __Customer_h
#define __Customer_h


#include <string>

class Customer {
	public:
		Customer(std::string name, std::string phone, std::string email);
		friend std::ostream& operator<<(std::ostream& ost, const Customer& customer);
	private:
		std::string _name;
		std::string _phone;
		std::string _email;

};

#endif
