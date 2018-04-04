/*
 * Accommodation.h
 *
 *  Created on: 23/03/2018
 *      Author: Francisco Miranda; João Vaz Gama Amaral; Maria Teresa Ferreira;
 */

#ifndef SRC_ACCOMMODATION_H_
#define SRC_ACCOMMODATION_H_

#include "Period.h"
#include "Libraries.h"

class Accommodation{
private:
	int basePrice;
	std::string name;
	std::vector<Period*> periods;
public:
	Accommodation();
	Accommodation(float price, std::string name, std::vector<Period*> periods);

	int getBasePrice();
	std::string getName();
	std::vector<Period*> getAllPeriods();
	Period* getPeriod(Date d);
	int getPrice(Date d);

	friend std::ostream & operator <<(std::ostream &o, const Accommodation &a){
		o << "The accommodation name is:" << a.name << std::endl;
		o << "It has a base price of: " << a.basePrice << std::endl;
		o << "All the seasons: " << std::endl;

		for(size_t i = 0; i < a.periods.size(); i++){
			o << "\t" << (*a.periods[i]) << std::endl;
			o << std::endl;
		}
		return o;
	}
};


#endif /* SRC_ACCOMMODATION_H_ */
