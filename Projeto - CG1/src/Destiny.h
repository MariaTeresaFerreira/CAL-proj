/*
 * Destiny.h
 *
 *  Created on: 23/03/2018
 *      Author: Francisco Miranda; João Vaz Gama Amaral; Maria Teresa Ferreira;
 */

#ifndef SRC_DESTINY_H_
#define SRC_DESTINY_H_

#include "Libraries.h"
#include "Accommodation.h"
#include "Coordinates.h"

class Destiny{

private:
	int ID;
	std::string cityName;
	std::vector<Accommodation*> accommodation;
	std::vector<Destiny*> destinies;
	Coordinates coordinates;
public:
	Destiny();
	Destiny(int ID, std::string cityName, std::vector<Accommodation*> accommodation, std::vector<Destiny*> destinies, Coordinates coordinates);

	int getID() const;
	std::string getCityName() const;
	std::vector<Accommodation*> getAllAccommodation();
	std::vector<Destiny*> getAllDestinies();
	Coordinates getCoord();

	void setID(int id);
	void setCityName(std::string name);
	void setCoordinates(Coordinates coord);

	bool operator ==(const Destiny& d);

	friend std::ostream& operator <<(std::ostream& o, const Destiny &d){

		o << "ID: " << d.ID << "\tCity Name: " << d.cityName;
		return o;

	}
};



#endif /* SRC_DESTINY_H_ */
