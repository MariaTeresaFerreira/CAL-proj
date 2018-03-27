/*
 * Accommodation.c
 *
 *  Created on: 23/03/2018
 *      Author: Francisco Miranda; João Vaz Gama Amaral; Maria Teresa Ferreira;
 */

#include "Accommodation.h"

Accommodation::Accommodation(string name, vector<int> prices){
	this->prices = prices;
	this->name = name;
}

string Accommodation::getName(){
	return this->name;
}

vector Accommodation::getPrices(){
	return this->prices;
}

void Accommodation::setName(string name){
	this->name = name;
}

void Accommodation::setPrice(int position, int price){
	this.prices.at(position) = price;
}




