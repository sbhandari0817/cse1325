#ifndef __taxed_h
#define __taxed_h


#include "product.h"

class Taxed: public Product{
    public:
	Taxed (std:: string name, double cost); //constructor
	virtual ~Taxed();
	double price() const override;
    	static void set_tax_rate (double sales_tax);
	private:
        static double tax;
};


#endif
