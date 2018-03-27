/*
 * Coordinates.c
 *
 *  Created on: 27/03/2018
 *      Author: Francisco Miranda; João Vaz Gama Amaral; Maria Teresa Ferreira;
 */
#include "Coordinates.h"

Coordinates::Coordinates(): x(0), y(0) {}

Coordinates::Coordinates(int x, int y){
	this->x = x;
	this->y = y;
}

int Coordinates::getX(){
	return this->x;
}

int Coordinates::getY(){
	return this->y;
}

void Coordinates::setX(int x){
	this->x = x;
}

void Coordinates::setY(int y){
	this->y = y;
}

void Coordinates::setCoord(int x, int y){
	this->x = x;
	this->y = y;
}
