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
