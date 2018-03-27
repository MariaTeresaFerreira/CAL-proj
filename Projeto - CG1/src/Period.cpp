/*
 * Period.cpp
 *
 *  Created on: 23/03/2018
 *      Author: Francisco Miranda; Jo�o Vaz Gama Amaral; Maria Teresa Ferreira;
 */

#include 'Period.h'

Period::Period(Date i, Date e, float p, string f, string s):
		init(i), end(e), price(p), festivity(f), season(s) {}

Period::Period(Date i, Date e, float p, string s):
		init(i), end(e), price(p), festivity(f), season(s) {

	this.festivity = "";
}

Date Period::getInit() const{
	return this.init;
}

Date Period::getEnd() const{
	return this.end;
}

float Period::getPrice() const{
	return this.price;
}

string Period::getFestivity() const{
	return this.festivity;
}

string Period::getSeason() const{
	return this.season;
}

void Peroid::setInit(Date d){
	this.init = d;
}
void Peroid::setEnd(Date d){
	this.end = d;
}
void Peroid::setPrice(float p){
	this.price = p;
}
void Peroid::setFestivity(string f){
	this.festivity = f;
}
void Peroid::setSeason(string s){
	this.season = s;
}
