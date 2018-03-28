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
	float tripPrice;
	float tripTime;
public:
	int getID() const;
	float getPrice();
	float getTime();
};

#endif /* POSSIBLEDESTINIES_H_ */
