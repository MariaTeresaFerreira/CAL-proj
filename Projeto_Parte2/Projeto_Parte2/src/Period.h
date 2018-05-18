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

	/**
	 * @brief Variable that stores the period's name
	 */
	std::string name;

	/**
	 * @brief Variable that stores the period's initial date
	 */
	Date init;

	/**
	 * @brief Variable that stores the period's final date
	 */
	Date end;

	/**
	 * @brief Variable that stores the period's additional price
	 */
	int price;
public:

	/**
	 * @brief Default constructor for the Period class
	 */
	Period();

	/**
	 * @brief Constructor for the Period class that sets the name, the initial date, the final date, and the additional as the received arguments
	 * @param name
	 * @param init
	 * @param end
	 * @param price
	 */
	Period(std::string name, Date *init, Date *end, int price);

	/**
	 * @brief Gets the period's initial date
	 * @return init
	 */
	Date getInit();

	/**
	 * @brief Gets the period's final date
	 * @return end
	 */
	Date getEnd();

	/**
	 * @brief Gets the period's initial day
	 * @return day of init
	 */
	int getInitDay();

	/**
	 * @brief Gets the period's initial month
	 * @return month of init
	 */
	int getInitMonth();

	/**
	 * @brief Gets the period's initial year
	 * @return year of init
	 */
	int getInitYear();

	/**
	 * @brief Gets the period's final day
	 * @return day of end
	 */
	int getEndDay();

	/**
	 * @brief Gets the period's final month
	 * @return month of end
	 */
	int getEndMonth();

	/**
	 * @brief Gets the period's final year
	 * @return year of end
	 */
	int getEndYear();

	/**
	 * @brief Gets the period's additional cost
	 * @return price
	 */
	int getPrice() const;

	/**
	 * @brief gets the period's name
	 * @return
	 */
	std::string getName();

	/**
	 * @brief Overloading of the << operator in order to present the information in a user friendly way
	 * @param o
	 * @param p
	 * @return ostream
	 */
	friend std::ostream & operator <<(std::ostream &o, const Period &p){
		o << "\tPeriod: " << p.name << std::endl;
		o << "\tDuration: " << p.init << " until " << p.end << std::endl;
		o << "\tAdditional price: " << p.price << std::endl;
		return o;
	}
};



#endif /* SRC_PERIOD_H_ */
