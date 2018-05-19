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
	/**
	 * @brief Variable that stores the last ID used to specify a destiny
	 */
	static int ultID;

	/**
	 * @brief Variable that stores the destiny's ID
	 */
	int ID;

	/**
	 * @brief Variable that stores the destiny's name
	 */
	std::string cityName;

	/**
	 * @brief Vector that stores all the accommodations available on the destiny
	 */
	std::vector<Accommodation*> accommodation;

	/**
	 * @brief Vector that stores all the possible destinies that can be accessed through the current destiny
	 */
	std::vector<PossibleDestinies*> destinies;

	/**
	 * @brief Variable that stores the destiny's coordinates
	 */
	Coordinates coordinates;

	/**
	 * @brief Vector that stores all the InterestPoints in this city
	 */
	std::vector<std::string> interestPoints;
public:

	/**
	 * @brief Default constructor for the Destiny class
	 */
	Destiny();

	/**
	 * @brief Constructor for the Destiny class that sets the ID, the city name, the accommodations vector, the destinies vector, and the coordinates as the received arguments
	 * @param ID
	 * @param cityName
	 * @param accommodation
	 * @param destinies
	 * @param coordinates
	 */
	Destiny(int ID, std::string cityName, std::vector<Accommodation*> accommodation, std::vector<PossibleDestinies*> destinies, Coordinates *coordinates);
	Destiny(std::string cityName, std::vector<Accommodation*> accommodation, std::vector<PossibleDestinies*> destinies, Coordinates *coordinates);
	Destiny(std::string cityName, Coordinates *coordinates);
	Destiny(std::string cityName, std::vector<Accommodation*> accommodation, std::vector<PossibleDestinies*> destinies, Coordinates *coordinates, std::vector<std::string> interestPoints);

	/**
	 * @brief Gets the destiny's ID
	 * @return ID
	 */
	int getID() const;

	/**
	 * @brief Gets the destiny's name
	 * @return cityName
	 */
	std::string getCityName() const;

	/**
	 * @brief Gets the destiny's accommodation vector
	 * @return accommodation
	 */
	std::vector<Accommodation*> getAllAccommodation() const;

	/**
	 * @brief Finds the cheapest accommodation in a destiny for the date passed as an argument
	 * @param d
	 * @return found accommodation
	 */
	Accommodation* cheapestAccommodation(Date d);

	/**
	 * @brief Finds a specific accommodation whose name is passed as the argument
	 * @param acc
	 * @return found accommodation
	 */
	Accommodation* findByName(std::string acc);

	/**
	 * @brief Gets the destiny's coordinates
	 * @return
	 */
	Coordinates getCoord();

	/**
	 * @brief Gets the destiny's destinies vector
	 * @return destinies
	 */
	std::vector<PossibleDestinies*> getAllDestinies();

	/**
	 * @brief Gets the number of destinations possible form the specific destination (size os the destinies vector)
	 * @return number of destinies
	 */
	int getNumberOfDest();

	/**
	 * @brief Gets the price of a trip to the destiny whose ID is passed as the argument
	 * @param id
	 * @return price of trip
	 */
	float getDestinyTripPrice(int id);

	/**
	 * @brief Gets the time of a trip to the destiny whose ID is passed as the argument
	 * @param id
	 * @return time of trip
	 */
	float getDestinyTripTime(int id);

	/**
	 * @brief Sets the destiny's ID to the value passed as an argument
	 * @param id
	 */
	void setID(int id);

	/**
	 * @brief Sets the destiny's city name to the name passed as an argument
	 * @param name
	 */
	void setCityName(std::string name);

	/**
	 * @brief Sets the destiny's coordinates to the values passed as arguments
	 * @param coord
	 */
	void setCoordinates(Coordinates coord);

	/**
	 * @brief Overloading of the == operator to compare two destinies
	 * @param d
	 * @return
	 */
	bool operator ==(const Destiny& d);

	/**
	 * @brief Overloading of the << operator in order to present the information in a user friendly way
	 * @param o
	 * @param d
	 * @return ostream
	 */
	friend std::ostream& operator <<(std::ostream& o, const Destiny &d){

		o << "\tID: " << d.ID << std::endl;
		o << "\tCity: " << d.cityName << std::endl;

		return o;
	}

	std::vector<std::string> getInterestPoints();
};

#endif /* SRC_DESTINY_H_ */
