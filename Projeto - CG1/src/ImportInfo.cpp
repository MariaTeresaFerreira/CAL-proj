/*
 * ImportInfo.cpp
 *
 *  Created on: 30/03/2018
 *      Author: Jo
 */

#include "ImportInfo.h"


void importClients(Agency& agency){

	std::ifstream clientsFile;
	clientsFile.open("InfoFiles/clients.txt");

	if(!clientsFile.good())
		std::cout << "Couldn't access clients.txt file. Error!" << std::endl;

	long int nif;
	std::string name, email, line;

	while(std::getline(clientsFile, line)){
		std::stringstream ss(line);
		std::string aux;
		std::stringstream auxSS;

		int id;
		std::getline(ss, aux, '/');
		auxSS << aux;
		auxSS >> id;

		aux.clear();
		auxSS.clear();
		auxSS.str(std::string());

		//NAME

		std::getline(ss, name, '/');

		//NIF

		std::getline(ss, aux, '/');
		auxSS << aux;
		auxSS >> nif;

		aux.clear();
		auxSS.clear();
		auxSS.str(std::string());

		//EMAIl

		std::getline(ss, email, '/');

		Client* c = new Client(id, name, nif, email);
		agency.addClient(c);
	}
	clientsFile.close();
}

void importCities(Agency& agency){
	std::ifstream citiesFile;
	citiesFile.open("InfoFiles/cities.txt");

	if(!citiesFile.good())
		std::cout << "Couldn't access cities.txt file. Error!" << std::endl;

	std::string name, line;
	int x, y;

	while(std::getline(citiesFile, line)){
		std::stringstream ss(line);
		std::string aux;
		std::stringstream auxSS;

		std::getline(ss, name, '/');

		std::getline(ss, aux, '/');
		auxSS << aux;
		auxSS >> x;

		aux.clear();
		auxSS.clear();
		auxSS.str(std::string());

		std::getline(ss, aux, '\n');
		auxSS << aux;
		auxSS >> y;

		aux.clear();
		auxSS.clear();
		auxSS.str(std::string());

		std::vector<Accommodation*> accommodations;
		std::vector<Destiny*> destinies;
		Coordinates* c = new Coordinates(x,y);

		Destiny* d = new Destiny(name, c);
		agency.addDestiny(d);
	}
	citiesFile.close();
}
