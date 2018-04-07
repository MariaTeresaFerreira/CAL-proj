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
	/**
	 * @brief Variable that stores the possible destiny's ID
	 */
	int ID;

	/**
	 * @brief Variable that stores the possible destiny's trip price
	 */
	int tripPrice;

	/**
	 * @brief Variable that stores the possible destiny's trip time
	 */
	int tripTime;
public:

	/**
	 * @brief Constructor for the PossibleDestinies class that sets the ID, the trip price, and the trip time as the received arguments
	 * @param ID
	 * @param trip
	 * @param time
	 */
	PossibleDestinies(int ID, int trip, int time);

	/**
	 * @brief Gets the possible destiny's ID
	 * @return ID
	 */
	int getID() const;

	/**
	 * @brief Gets the possible destiny's trip price
	 * @return tripPrice
	 */
	int getPrice();

	/**
	 * @brief Gets the possible destiny's trip time
	 * @return tripTime
	 */
	int getTime();

	/**
	 * @brief Overloading of the << operator in order to present the information in a user friendly way
	 * @param o
	 * @param d
	 * @return ostream
	 */
	friend std::ostream& operator <<(std::ostream& o, const PossibleDestinies &d){

		o << "ID: " << d.ID << std::endl;
		o << "Trip price: " << d.tripPrice << std::endl;
		o << "Trip time: " << d.tripTime << std::endl;

		return o;

	}
};

#endif /* POSSIBLEDESTINIES_H_ */
