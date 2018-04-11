/*
 * ExportInfor.cpp
 *
 *  Created on: 30/03/2018
 *      Author: Jo
 */
#include "ExportInfo.h"

void exportClients(Agency& agency){

	int i;
	int clientsSize = agency.getClients().size();

	std::ofstream clientsFile;
	clientsFile.open("InfoFiles/clients.txt", std::ios::trunc);

	for(i = 0; i < clientsSize; i++){
		std::string infoClient;
		Client* c = agency.getClients()[i];


		std::string line;
		std::stringstream ss;
		std::string delimiter = "/";

		//ID
		std::string id;
		int auxID = c->getID();
		ss << auxID;
		ss >> id;
		ss.clear();
		ss.str(std::string());

		line.append(id).append(delimiter);

		//NAME
		std::string name;
		name = c->getName();

		//NIF
		std::string nif;
		long int auxNif = c->getNIF();
		ss << auxNif;
		ss >> nif;
		ss.clear();
		ss.str(std::string());

		//EMAIL
		std::string email;
		email = c->getEmail();

		line.append(name).append(delimiter).append(nif).append(delimiter).append(email).append("\n");

		infoClient = line;

		clientsFile << infoClient;
	}

	clientsFile.close();

}

void exportInfoFlight1(int id, std::string accommodation, int cost, Destiny &d){

	std::ofstream reservationFile;
	std::string infoReservation;
	reservationFile.open("InfoFiles/reservations.txt", std::ios::app);

	std::string line;
	std::stringstream ss;
	std::string delimiter = "/";

	//ID
	std::string ID;
	int auxID = id;
	ss << auxID;
	ss >> ID;
	ss.clear();
	ss.str(std::string());

	//COST
	std::string totalCost;
	int auxCost = cost;
	ss << auxCost;
	ss >> totalCost;
	ss.clear();
	ss.str(std::string());

	//NAME
	std::string destName;
	destName = d.getCityName();

	line.append(ID).append(delimiter).append(destName).append(delimiter).append(accommodation).append(delimiter).append(totalCost).append("\n");

	infoReservation = line;

	reservationFile << infoReservation;

	reservationFile.close();
}

void exportInfoFlight2(int id, std::vector<Accommodation*> a, std::vector<string> stops, int cost){

	std::ofstream reservationFile;
	std::string infoReservation;
	reservationFile.open("InfoFiles/reservations.txt", std::ios::app);

	std::string line;
	std::stringstream ss;
	std::string delimiter = "/";

	//ID
	std::string ID;
	int auxID = id;
	ss << auxID;
	ss >> ID;
	ss.clear();
	ss.str(std::string());
	line.append(ID).append(delimiter);

	for(unsigned int i = 0; i < a.size(); i++){
		line.append(a[i]->getName()).append(delimiter);
	}

	for(unsigned int i = 0; i < stops.size(); i++){
		line.append(stops[i]).append(delimiter);
	}

	//COST
	std::string totalCost;
	int auxCost = cost;
	ss << auxCost;
	ss >> totalCost;
	ss.clear();
	ss.str(std::string());
	line.append(totalCost).append("\n");

	infoReservation = line;
	reservationFile << infoReservation;

	reservationFile.close();
}
