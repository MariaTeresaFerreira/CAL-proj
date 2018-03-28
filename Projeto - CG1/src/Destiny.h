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
#include "PossibleDestinies.h"

class Destiny{

private:
	int ID;
	std::string cityName;
	std::vector<Accommodation*> accommodation;
	std::vector<PossibleDestinies*> destinies;
	Coordinates coordinates;
public:
	Destiny();
	Destiny(int ID, std::string cityName, std::vector<Accommodation*> accommodation, std::vector<PossibleDestinies*> destinies, Coordinates coordinates);

	int getID() const;
	std::string getCityName() const;
	std::vector<Accommodation*> getAllAccommodation();
	Accommodation* cheapestAccommodation(Date d);
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
		o << "Accommodations available: " << std::endl;
		for(size_t i = 0; i < d.accommodation.size(); i++){
			o << (*d.accommodation[i]) << std::endl;
		}
		//Parte dos destinos ainda a definir
		return o;

	}
};



#endif /* SRC_DESTINY_H_ */
