/*
 * Period.h
 *
 *  Created on: 23/03/2018
 *      Author: Francisco Miranda; Jo�o Vaz Gama Amaral; Maria Teresa Ferreira;
 */

#ifndef SRC_PERIOD_H_
#define SRC_PERIOD_H_

#include "Date.h"

class Period{
	std::string name;
	Date init;
	Date end;
	float price;
public:
	Period();
	Period(std::string name, Date *init, Date *end, float price);

	Date getInit();
	Date getEnd();

	int getInitDay();
	int getInitMonth();
	int getInitYear();

	int getEndDay();
	int getEndMonth();
	int getEndYear();

	float getPrice() const;

	std::string getName();

	friend std::ostream & operator <<(std::ostream &o, const Period &p){
		o << "\tPeriod: " << p.name << std::endl;
		o << "\tDuration: " << p.init << " until " << p.end << std::endl;
		o << "\tAdditional price: " << p.price << std::endl;
		return o;
	}
};



#endif /* SRC_PERIOD_H_ */
