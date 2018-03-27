/*
 * Period.cpp
 *
 *  Created on: 23/03/2018
 *      Author: Francisco Miranda; Jo�o Vaz Gama Amaral; Maria Teresa Ferreira;
 */

#include "Period.h"

Period::Period(){
	name = "";
	init = Date();
	end = Date();
	price = 0;
}

Period::Period(std::string name, Date init, Date end, float price):
	name(name), init(init), end(end), price(price){}

Date Period::getInit(){
	return init;
}

Date Period::getEnd(){
	return end;
}

float Period::getPrice() const{
	return price;
}

int Period::getInitDay(){
	return init.getDay();
}

int Period::getInitMonth(){
	return init.getMonth();
}

int Period::getInitYear(){
	return init.getYear();
}

int Period::getEndDay(){
	return end.getDay();
}

int Period::getEndMonth(){
	return end.getMonth();
}

int Period::getEndYear(){
	return end.getYear();
}

std::string Period::getName(){
	return name;
}
