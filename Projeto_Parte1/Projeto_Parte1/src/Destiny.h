/*
 * Destiny.h
 *
 *  Created on: 23/03/2018
 *      Author: Francisco Miranda; Jo�o Vaz Gama Amaral; Maria Teresa Ferreira;
 */

#ifndef SRC_DESTINY_H_
#define SRC_DESTINY_H_

#include "Libraries.h"
#include "Accommodation.h"
#include "Coordinates.h"
#include "PossibleDestinies.h"

class Destiny{

private:
	static int ultID;
	int ID;
	std::string cityName;
	std::vector<Accommodation*> accommodation;
	std::vector<PossibleDestinies*> destinies;
	Coordinates coordinates;
public:
	Destiny();
	Destiny(int ID, std::string cityName, std::vector<Accommodation*> accommodation, std::vector<PossibleDestinies*> destinies, Coordinates *coordinates);
	Destiny(std::string cityName, std::vector<Accommodation*> accommodation, std::vector<PossibleDestinies*> destinies, Coordinates *coordinates);
	Destiny(std::string cityName, Coordinates *coordinates);

	int getID() const;
	std::string getCityName() const;
	std::vector<Accommodation*> getAllAccommodation() const;
	Accommodation* cheapestAccommodation(Date d);
	Accommodation* findByName(std::string acc);
	Coordinates getCoord();

	std::vector<PossibleDestinies*> getAllDestinies();
	int getNumberOfDest();
	float getDestinyTripPrice(int id);
	float getDestinyTripTime(int id);

	void setID(int id);
	void setCityName(std::string name);
	void setCoordinates(Coordinates coord);

	bool operator ==(const Destiny& d);

	friend std::ostream& operator <<(std::ostream& o, const Destiny &d){

		o << "ID: " << d.ID << std::endl;
		o << "City: " << d.cityName << std::endl;

		return o;

	}
};



#endif /* SRC_DESTINY_H_ */