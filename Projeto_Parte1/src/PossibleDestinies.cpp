/*
 * PossibleDestinies.cpp
 *
 *  Created on: 28/03/2018
 *      Author: Jo
 */
#include "PossibleDestinies.h"

PossibleDestinies::PossibleDestinies(int ID, int trip, int time): ID(ID), tripPrice(trip), tripTime(time){}

int PossibleDestinies::getID() const{
	return ID;
}

int PossibleDestinies::getPrice(){
	return tripPrice;
}

int PossibleDestinies::getTime(){
	return tripTime;
}
