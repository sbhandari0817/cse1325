#include "coin.h"
#include "logger.h"
#include <string>
#include <iostream>

//Constructor: This will construct size and year from matching parameters and _notes to nullptr also Log the message. 

Coin::Coin (Coin_size size, Year year): _size{size},_year{year}{
	_notes = NULL;
	LOG ("Coin:: Coin");
}

//Copy Constructor: Here it will construct size and year from rhs attributes and make a deep copy of notes. 

Coin::Coin(const Coin &rhs): _size(rhs._size), _year(rhs._year){
	_notes = new std:: string;
	*(this->_notes) = *(rhs._notes);
	LOG("Coin::Coin copy Constructor");
}
Coin &Coin::operator = (const Coin &rhs)
{
	_year=rhs._year;
	_size=rhs._size;
	_notes=new std::string;
	*(_notes)=*(rhs._notes);
	LOG("Coin::Coin assignment =");
}
//Implimentation of destructor 

Coin:: ~Coin(){
	delete _notes;
	LOG ("Coin::~Coin");
}

void Coin:: add_note(std:: string s){
	if (_notes==NULL){
	_notes = new std::string;
	*(this ->_notes) = s;
	}
	else *(this->_notes) += s;

}

std::ostream& operator << (std::ostream& ost, const Coin_size& coin_size){
	switch (coin_size){
		case Coin_size:: PENNY: ost <<"PENNY";break;
		case Coin_size:: NICKEL: ost <<"NICKEL";break;
		case Coin_size:: DIME: ost <<"DIME";break;
		case Coin_size:: QUATER: ost << "QUATAR";break;
		default: throw std::runtime_error("There is not any such sized coin");
	}
	return ost;
}
std::ostream& operator << (std::ostream& ost, const Coin& coin){
	ost<<coin._year << " " << coin._size << "\n"<<*(coin._notes)<<std::endl;
	return ost;
}

