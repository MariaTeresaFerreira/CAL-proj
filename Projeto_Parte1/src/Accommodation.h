/*
 * Accommodation.h
 *
 *  Created on: 23/03/2018
 *      Author: Francisco Miranda; Jo�o Vaz Gama Amaral; Maria Teresa Ferreira;
 */

#ifndef SRC_ACCOMMODATION_H_
#define SRC_ACCOMMODATION_H_

#include "Period.h"
#include "Libraries.h"

class Accommodation{
private:
    /**
     * @brief Variable that stores the accommodation price with no added cost
     */
	int basePrice;
    /**
     * @brief Variable that stores the accommodation facility's name
     */
	std::string name;
    /**
     * @brief Vector that stores the different periods that affect the accommodation's price
     */
	std::vector<Period*> periods;
public:
    /**
     * @brief Default constructor for the Accommodation class
     */
	Accommodation();
    /**
     * @brief Constructor for the Accommodation class that sets the price, the name, and the periods vector as the received arguments
     * @param price
     * @param name
     * @param periods
     */
	Accommodation(float price, std::string name, std::vector<Period*> periods);

    /**
     * @brief Gets the current value of the base price of the accommodation
     * @return basePrice
     */
	int getBasePrice();

    /**
     * @brief Gets the current name of the accommodation
     * @return name
     */
	std::string getName();

    /**
     * @brief  Gets the current periods vector
     * @return periods
     */
	std::vector<Period*> getAllPeriods();

    /**
     * @brief Returns the period that the date given as an argument is inserted into
     * @param d
     * @return Period
     */
	Period* getPeriod(Date d);

    /**
     * @brief Calculates the final price for the given date with the base price and the period that the date is from
     * @param d
     * @return price for the given date
     */
	int getPrice(Date d);

    /**
     * @brief Overloading of the << operator in order to present the information in a user friendly way
     * @param o
     * @param a
     * @return ostream
     */
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
