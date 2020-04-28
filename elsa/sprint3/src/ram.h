#ifndef __RAM_H_
#define __RAM_H_

#include <string>
#include <fstream>
#include <iostream>

class Ram: public Options{
	public:
		Ram(std::string name, double cost, int gb);
		~virtual Ram();
		std::string to_string() const override;
		void Ram (std::istream& ist);
		void save(std::ostream& ost) override;
	protected:
		int _gb;

}
