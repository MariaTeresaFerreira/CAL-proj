/*
 * Accommodation.c
 *
 *  Created on: 23/03/2018
 *      Author: Francisco Miranda; João Vaz Gama Amaral; Maria Teresa Ferreira;
 */

#include "Accommodation.h"

Accommodation::Accommodation(std::string name, Period period){
	this->name = name;
	this->period = period
}

std::string Accommodation::getName() const{
	return this->name;
}

Accommodation::getPeriod() const{
	return this->period;
}

void Accommodation::setName(std::string name){
	this->name = name;
}

void Accommodation::setPeriod(Period period){
	this->period = period;
}




