/*
 * Coordinates.h
 *
 *  Created on: 27/03/2018
 *      Author: Francisco Miranda; Jo�o Vaz Gama Amaral; Maria Teresa Ferreira;
 */

#ifndef COORDINATES_H_
#define COORDINATES_H_
#include "Libraries.h"

class Coordinates{
private:
	/**
	 * @brief x coordinate
	 */
	int x;

	/**
	 * @brief y coordinate
	 */
	int y;
public:
	/**
	 * @brief Default constructor for the Coordinates class
	 */
	Coordinates();

	/**
	 * @brief Constructor for the Coordinates class that sets the x and y coordinates to the values passed as arguments
	 * @param x
	 * @param y
	 */
	Coordinates(int x, int y);

	/**
	 * @brief Gets the x cordinate
	 * @return x
	 */
	int getX();

	/**
	 * @brief Gets the y coordinate
	 * @return y
	 */
	int getY();

	/**
	 * @brief Sets the x coordinate to the value passed as an argument
	 * @param x
	 */
	void setX(int x);

	/**
	 * @brief Sets the y coordinate to the value passed as an argument
	 * @param y
	 */
	void setY(int y);

	/**
	 * @brief Sets the x and y coordinates to the values passed as arguments
	 * @param x
	 * @param y
	 */
	void setCoord(int x, int y);

};




#endif /* COORDINATES_H_ */
