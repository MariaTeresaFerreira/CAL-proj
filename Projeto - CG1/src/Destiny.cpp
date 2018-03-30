/*
 * Destiny.c
 *
 *  Created on: 23/03/2018
 *      Author: Francisco Miranda; João Vaz Gama Amaral; Maria Teresa Ferreira;
 */
#include "Destiny.h"
#define MAX_PRICE 999999999
int Destiny::ultID = 1;

Destiny::Destiny(): ID(0), cityName(""){
	accommodation = *(new std::vector<Accommodation*>());
	destinies = *(new std::vector<PossibleDestinies*>());
	coordinates = Coordinates();
}

Destiny::Destiny(int ID, std::string cityName, std::vector<Accommodation*> accommodation, std::vector<PossibleDestinies*> destinies, Coordinates *coordinates){
	this->ID = ID;
	this->cityName = cityName;
	this->accommodation = accommodation;
	this->destinies = destinies;
	this->coordinates.setX(coordinates->getX());
	this->coordinates.setY(coordinates->getY());
}

Destiny::Destiny(std::string cityName, Coordinates *coordinates){
	this->ID = ultID++;
	this->cityName = cityName;
	this->accommodation = *(new std::vector<Accommodation*>());
	this->destinies = *(new std::vector<PossibleDestinies*>());
	this->coordinates.setX(coordinates->getX());
	this->coordinates.setY(coordinates->getY());
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

	std::vector<Accommodation*>::iterator it = accommodation.begin();

	Accommodation *place = new Accommodation();
	int lowest_price = MAX_PRICE;

	for(; it!=accommodation.end(); it++){

		float price = ((*it)->getBasePrice() + (*it)->getPrice(d));

		if(price < lowest_price){

			lowest_price = price;

			place = (*it);

		}

	}
	return place;
}

std::vector<PossibleDestinies*> Destiny::getAllDestinies(){
	return destinies;
}

int Destiny::getNumberOfDest(){
	return this->destinies.size();
}

float Destiny::getDestinyTripPrice(int id){

	std::vector<PossibleDestinies*>::iterator it = destinies.begin();

	for(; it != destinies.end(); it++){
		int tempID = (*it)->getID();
		if(tempID == id){
			return (*it)->getPrice();
		}
	}
	return -1;
}

float Destiny::getDestinyTripTime(int id){

	std::vector<PossibleDestinies*>::iterator it = destinies.begin();

	for(; it != destinies.end(); it++){
		int tempID = (*it)->getID();
		if(tempID == id){
			return (*it)->getTime();
		}
	}
	return -1;
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
