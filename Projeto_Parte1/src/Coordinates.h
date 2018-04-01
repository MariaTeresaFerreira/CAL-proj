/*
 * Coordinates.h
 *
 *  Created on: 27/03/2018
 *      Author: Francisco Miranda; João Vaz Gama Amaral; Maria Teresa Ferreira;
 */

#ifndef COORDINATES_H_
#define COORDINATES_H_
#include "Libraries.h"

class Coordinates{
private:
	int x;
	int y;
public:
	Coordinates();
	Coordinates(int x, int y);
	int getX();
	int getY();
	void setX(int x);
	void setY(int y);
	void setCoord(int x, int y);

};




#endif /* COORDINATES_H_ */
