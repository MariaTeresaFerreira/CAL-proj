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

Period::Period(std::string name, Date *init, Date *end, int price): name(name), price(price){
	this->init.setDay(init->getDay());
	this->init.setMonth(init->getMonth());

	this->end.setDay(end->getDay());
	this->end.setMonth(end->getMonth());
}

Date Period::getInit(){
	return init;
}

Date Period::getEnd(){
	return end;
}

int Period::getPrice() const{
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
