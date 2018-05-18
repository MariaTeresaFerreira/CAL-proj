/*
 * Clients.cpp
 *
 *  Created on: 30/03/2018
 *      Author: Jo
 */
#include "Clients.h"

int Client::ultID = 1;

Client::Client(std::string name, unsigned long nif, std::string email){
	this->id = ultID++;
	this->name = name;
	this->NIF = nif;
	this->email = email;
}

Client::Client(int id, std::string name, unsigned long nif, std::string email){
	this->id = id;
	this->name = name;
	this->NIF = nif;
	this->email = email;
	ultID = ++id;
}

int Client::getID() const{
	return this->id;
}

std::string Client::getName() const{
	return this->name;
}

unsigned long Client::getNIF() const{
	return this->NIF;
}

std::string Client::getEmail() const{
	return this->email;
}

void Client::setName(std::string name) {
	this->name = name;
}

void Client::setNIF(unsigned long nif){
	this->NIF = nif;
}

void Client::setEmail(std::string email){
	this->email = email;
}








