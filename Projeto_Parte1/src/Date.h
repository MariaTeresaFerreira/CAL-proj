/*
 * Date.h
 *
 *  Created on: 23/03/2018
 *      Author: Francisco Miranda; Jo�o Vaz Gama Amaral; Maria Teresa Ferreira;
 */

#ifndef SRC_DATE_H_
#define SRC_DATE_H_

#include "Libraries.h"

class Date{

	/**
	 * @brief Variable that stores the day of the date
	 */
	int day;

	/**
	 * @brief Variable that stores the month of the date
	 */
	int month;

	/**
	 * @brief Variable that stores the year of the date
	 */
	int year;

	/**
	 * @brief Variable that stores the hour of the date
	 */
	int hour;

	/**
	 * @brief Variable that stores the minute of the date
	 */
	int minute;
public:

	/**
	 * @brief Default constructor for the Date class
	 */
	Date();

	/**
	 * @brief Constructor for the Date class that sets the day and the month as the received arguments
	 * @param d
	 * @param m
	 */
	Date(int d, int m);

	/**
	 * @brief Constructor for the Date class that sets the day, the month, and the year as the received arguments
	 * @param d
	 * @param m
	 * @param y
	 */
	Date(int d, int m, int y);

	/**
	 * @brief Constructor for the Date class that sets the day, the month, the year, the hour, and the minute as the received arguments
	 * @param d
	 * @param m
	 * @param y
	 * @param h
	 * @param min
	 */
	Date(int d, int m, int y, int h, int min);

	/**
	 * @brief Gets the day of the date
	 * @return day
	 */
	int getDay() const;

	/**
	 * @brief Gets the month of the date
	 * @return month
	 */
	int getMonth() const;

	/**
	 * @brief Gets the year of the date
	 * @return year
	 */
	int getYear() const;

	/**
	 * @brief Gets the hour of the date
	 * @return hour
	 */
	int getHour() const;

	/**
	 * @brief Gets the minute of the date
	 * @return minute
	 */
	int getMinute() const;

	/**
	 * @brief Sets the day of the date to the value passed as an argument
	 * @param d
	 */
	void setDay(int d);

	/**
	 * @brief Sets the month of the date to the value passed as an argument
	 * @param m
	 */
	void setMonth(int m);

	/**
	 * @brief Sets the year of the date to the value passed as an argument
	 * @param y
	 */
	void setYear(int y);

	/**
	 * @brief Sets the minute of the date to the value passed as an argument
	 * @param min
	 */
	void setMinute(int min);

	/**
	 * @brief Sets the hour of the date to the value passed as an argument
	 * @param h
	 */
	void setHour(int h);

	/**
	 * @brief Overloading of the >= operator to compare two dates
	 * @param d
	 * @return
	 */
	bool operator >=(const Date& d);

	/**
	 * @brief Overloading of the <= operator to compare two dates
	 * @param d
	 * @return
	 */
	bool operator <=(const Date& d);

	/**
	 * @brief Overloading of the == operator to compare two dates
	 * @param d
	 * @param d1
	 * @return
	 */
	friend bool operator ==(const Date& d, const Date& d1){
		if(d.day == d1.getDay() && d.month == d1.getMonth() && d.year == d1.getYear())
			return true;
		return false;
	}

	/**
	 * @brief Overloading of the << operator in order to present the information in a user friendly way
	 * @param o
	 * @param d
	 * @return
	 */
	friend std::ostream& operator <<(std::ostream& o, const Date& d){
		o << d.day << "/" << d.month << "/" << "year"; //Tenho year porque os anos s�o um pouco irrelevantes.
/*
		if(d.hour < 10)
			o << "0" << d.hour;
		else
			o << d.hour;

		if(d.minute < 10)
			o << "0" << d.minute;
		else
			o << d.minute;
*/
		return o;
	}

	/**
	 * @brief Overloading of the < operator to compare two dates
	 * @param d1
	 * @param d2
	 * @return
	 */
	friend bool operator <(const Date& d1, const Date& d2){
		if(d1.year < d2.getYear())
				return true;
		else if(d1.year > d2.getYear())
			return false;

		if(d1.month < d2.getMonth())
				return true;
		else if(d1.month > d2.getMonth())
			return false;

		if(d1.day < d2.getDay())
			return true;
		return false;
	}
};

#endif /* SRC_DATE_H_ */
