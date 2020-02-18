#ifndef __coin_h
#define __coin_h

#include <iostream>
enum class Coin_size {PENNY, NICKEL, DIME, QUATER};
typedef int Year;

class Coin{
	
	public:
		Coin(Coin_size size, Year year);
		Coin(const Coin &rhs); 
		Coin &operator = (const Coin &rhs); 
		~Coin();
		void add_note (std:: string _notes);
		friend std::ostream& operator << (std::ostream& ost, const Coin& coin);
		
	private:
		Coin_size _size;
		Year _year;
		std:: string* _notes; 

};

#endif
