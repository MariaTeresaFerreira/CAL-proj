/*
 * Accommodation.c
 *
 *  Created on: 23/03/2018
 *      Author: Francisco Miranda; João Vaz Gama Amaral; Maria Teresa Ferreira;
 */

#include "Accommodation.h"

Accommodation::Accommodation(string name, Period period){
	this->name = name;
	this->period = period
}

string Accommodation::getName(){
	return this->name;
}

vector Accommodation::getPeriod(){
	return this->period;
}

void Accommodation::setName(string name){
	this->name = name;
}

void Accommodation::setPeriod(Period period){
	this->period = period;
}




