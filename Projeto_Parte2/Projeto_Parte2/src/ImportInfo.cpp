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

	int counter = 1;
	std::string path = "./InfoFiles/";
	std::ifstream in;
	std::string nameCity, nameA, nameP, nameI, temp;
	unsigned int x, y, count1, count2;

	while(counter <= 20/* mudar consoante os ficheiros*/){
		std::ostringstream converter;
		converter << counter;
		std::string fich = path + converter.str() + ".txt";
		const char *nameFich;
		nameFich= fich.c_str();

		in.open(nameFich);

		if(!in.fail()){
			std::getline(in, nameCity);
			std::getline(in, temp, ',');
			x = atoi(temp.c_str());
			std::getline(in, temp);
			y = atoi(temp.c_str());

			Coordinates *cords = new Coordinates(x, y);

			std::getline(in, temp);
			count1 = atoi(temp.c_str());

			//CICLO Alojamento
			std::vector<Accommodation*> accommodations;
			for(size_t i = 0; i < count1; i++){
				std::getline(in,nameA);
				std::getline(in,temp);
				count2 = atoi(temp.c_str());

				//CICLO Epocas
				std::vector<Period*> periods;
				for(size_t k = 0; k < count2; k++){
					int dayI, dayF, monthI, monthF;
					float price;
					std::getline(in, nameP);
					std::getline(in, temp, '-');
					dayI = atoi(temp.c_str());
					std::getline(in, temp, '/');
					monthI = atoi(temp.c_str());
					std::getline(in, temp, '-');
					dayF = atoi(temp.c_str());
					std::getline(in, temp);
					monthF = atoi(temp.c_str());

					std::getline(in, temp);
					price = atoi(temp.c_str());

					Date* init = new Date(dayI, monthI);
					Date* end = new Date(dayF, monthF);

					Period* period = new Period(nameP, init, end, price);
					periods.push_back(period);
				}
				float f = 50 + rand() %500;
				Accommodation* accommodation = new Accommodation(f, nameA, periods);
				accommodations.push_back(accommodation);
			}

			std::getline(in, temp);
			count1 = atoi(temp.c_str());

			//CICLO DESTINOS
			std::vector<PossibleDestinies*> pDestinies;

			for(size_t i = 0; i < count1; i++){

				std::getline(in, temp);
				int ID = atoi(temp.c_str());
				std::getline(in, temp);
				int price = atoi(temp.c_str());
				std::getline(in, temp);
				int time = atoi(temp.c_str());

				PossibleDestinies *p = new PossibleDestinies(ID, price, time);
				pDestinies.push_back(p);
			}

			//2 PARTE A PARTIR DAQUI FALTA PREENCHER FICHEIROS DE TEXTO
			std::vector<std::string> interestPoints;
			std::getline(in, temp);
			count1 = atoi(temp.c_str());
			//CICLO DE PONTOS DE INTERESSE
			for(size_t i = 0; i < count1; i++){
				std::getline(in, temp);
				interestPoints.push_back(temp);
			}

			Destiny destiny = Destiny(nameCity, accommodations, pDestinies, cords, interestPoints);
			agency.addDestiny(destiny);

			agency.addVertex(destiny);

			in.close();
		}
		counter++;
	}
}

void loadEdgesTime(Agency& agency){

	for(size_t i = 0 ; i < agency.getDestinies().size(); i++){

		Destiny origin = agency.getDestinies()[i];

		for(size_t j = 0; j < origin.getAllDestinies().size(); j++){

			int id = origin.getAllDestinies()[j]->getID();
			double time = origin.getAllDestinies()[j]->getTime();

			Destiny dest = searchID(agency.getDestinies(), id);

			agency.addEdge(origin, dest, time);

		}
	}
}

void loadEdgesCost(Agency& agency){

	for(size_t i = 0 ; i < agency.getDestinies().size(); i++){

		Destiny origin = agency.getDestinies()[i];

		for(size_t j = 0; j < origin.getAllDestinies().size(); j++){

			int id = origin.getAllDestinies()[j]->getID();
			double cost = origin.getAllDestinies()[j]->getPrice();

			Destiny dest = searchID(agency.getDestinies(), id);

			agency.addEdge(origin, dest, cost);

		}
	}
}


