/*
 * Destiny.c
 *
 *  Created on: 23/03/2018
 *      Author: Francisco Miranda; João Vaz Gama Amaral; Maria Teresa Ferreira;
 */
#include "Destiny.h"

Destiny::Destiny(): ID(0), cityName(""){
	accommodation = *(new std::vector<Accommodation*>());
	destinies = *(new std::vector<Destiny*>());
	coordinates = Coordinates();
}

Destiny::Destiny(int ID, std::string cityName, std::vector<Accommodation*> accommodation, std::vector<Destiny*> destinies, Coordinates coordinates){
	this->ID = ID;
	this->cityName = cityName;
	this->accommodation = accommodation;
	this->destinies = destinies;
	this->coordinates = coordinates;
}

int Destiny::getID() const{
	return ID;
}

std::string Destiny::getCityName() const{
	return cityName;
}

std::vector<Accommodation*> Destiny::getAllAccommodation(){
	return accommodation;
}

Accommodation* Destiny::cheapestAccommodation(Date d){
	//TODO
}

std::vector<Destiny*> Destiny::getAllDestinies(){
	return destinies;
}

int Destiny::getNumberOfDest(){
	//TODO
	return 0;
}

Coordinates Destiny::getCoord(){
	return coordinates;
}

void Destiny::setID(int id){
	this->ID = id;
}

void Destiny::setCityName(std::string name){
	this->cityName = name;
}

void Destiny::setCoordinates(Coordinates coord){
	this->coordinates = coord;
}

bool Destiny::operator ==(const Destiny& d){
	if(ID == d.getID()) return true;
	return false;
}
