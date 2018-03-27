/*
 * Accommodation.c
 *
 *  Created on: 23/03/2018
 *      Author: Francisco Miranda; João Vaz Gama Amaral; Maria Teresa Ferreira;
 */

#include "Accommodation.h"

Accommodation::Accommodation(){
	basePrice = 0;
	name = "";
	periods = *(new std::vector<Period*>());
}

Accommodation::Accommodation(float price, std::string name, std::vector<Period*> periods):
	basePrice(price), name(name), periods(periods){}

float Accommodation::getBasePrice(){
	return basePrice;
}

std::string Accommodation::getName(){
	return name;
}

std::vector<Period*> Accommodation::getAllPeriods(){
	return periods;
}

Period* Accommodation::getPeriod(Date d){
	//TODO
}

float Accommodation::getPrice(Date d){
	//TODO, DEPENDE DA ANTERIOR
}
