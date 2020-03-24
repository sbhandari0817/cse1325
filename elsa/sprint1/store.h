#ifndef __Store_h
#define __Store_h
class Store{
	public:
		void add_customer(Customer& customer);
		int num_customers();
		Customer& customer(int index);
		void add_option(Options& option);
		int num_options();
		Options& option(int index);
		int new_desktop();
		void add_option(int option, int desktop);
		int num_desktop();
		Desktop& desktop(index:int);
		int new_order(int customer);
		void add_desktop(int desktop, int order);
		int num_orders();
		Order& order(int index);
	private:
		std::vector<Customer>customers;
		std::vector<Options> options;
		std::vector<Desktop> desktops;
		std::vector<Order> orders;
}
#endif;

