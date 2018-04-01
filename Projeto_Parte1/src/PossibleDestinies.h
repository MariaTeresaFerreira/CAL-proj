/*
 * PossibleDestinies.h
 *
 *  Created on: 28/03/2018
 *      Author: Jo
 */

#ifndef POSSIBLEDESTINIES_H_
#define POSSIBLEDESTINIES_H_

#include "Libraries.h"

class PossibleDestinies{
private:
	int ID;
	int tripPrice;
	int tripTime;
public:
	PossibleDestinies(int ID, int trip, int time);
	int getID() const;
	float getPrice();
	float getTime();

	friend std::ostream& operator <<(std::ostream& o, const PossibleDestinies &d){

		o << "ID: " << d.ID << std::endl;
		o << "Trip price: " << d.tripPrice << std::endl;
		o << "Trip time: " << d.tripTime << std::endl;

		return o;

	}
};

#endif /* POSSIBLEDESTINIES_H_ */
