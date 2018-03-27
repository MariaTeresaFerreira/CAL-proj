/*
 * Accommodation.h
 *
 *  Created on: 23/03/2018
 *      Author: Francisco Miranda; João Vaz Gama Amaral; Maria Teresa Ferreira;
 */

#ifndef SRC_ACCOMMODATION_H_
#define SRC_ACCOMMODATION_H_

#include "Period.h"

class Accommodation{
private:
	string name;
	Period period;
	//vetor com as epocas diferentes para atribuir preço
public:
	Accomodation(string name, Period period);

	string getName();
	Period getPeriod();

	void setName(string name);
	void setPeriod(Period period);

};


#endif /* SRC_ACCOMMODATION_H_ */
