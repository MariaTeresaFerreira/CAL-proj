/*
 * Interface.cpp
 *
 *  Created on: 29/03/2018
 *      Author: Jo
 */
#include "Libraries.h"
#include "Interface.h"

void initMenu(Agency& agency){
	bool exit = false;

	while(!exit){
		int option = showMenu(agency);

		switch(option){
		case 1:
			exit = clientsMenu(agency);
			break;
		case 2:
			exit = mapMenu(agency);
			break;
		case 3:
			exit = flightMenu(agency);
			break;
		case 4:
			exit = destiniesMenu(agency);
			break;
		case -1:
			exit = true;
			break;
		}
		if(exit) break;
	}
}

int showMenu(Agency& agency){
	int option;
	std::cout << "MENU:" << std::endl;
	std::cout << "\t 1 - Clients" << std::endl;
	std::cout << "\t 2 - Open Map" << std::endl;
	std::cout << "\t 3 - Choose your trip" << std::endl;
	std::cout << "\t 4 - Operating cities and possible destinies" << std::endl;
	std::cout << "\t-1 - Quit" << std::endl;

	std::cin >> option;
	return option;
}













//CLIENTS INTERFACE

bool clientsMenu(Agency& agency){
	int option;

	while(option != -1){
		std::cout <<"\n\tCLIENTS\n" << std::endl;
		std::cout << "\t1 - Check client" << std::endl;
		std::cout << "\t2 - Add client" << std::endl;
		std::cout << "\t3 - Check all clients" << std::endl;
		std::cout << "\t0 - Go back" << std::endl;
		std::cout << "\t-1 - Exit program.\n" << std::endl;

		int instruction;

		std::cout << "\nPlease enter an option: ";
		std::cin >> option;

		switch(option){
		case 1:
			instruction = checkClient(agency);
			break;
		case 2:
			instruction = addClient(agency);
			break;
		case 3:
			instruction = checkAllclients(agency);
			break;
		case 0:
			return false;
		case -1:
			instruction = -1;
			break;
		default:
			std::cout << "\nPlease insert a valid option." << std::endl;
			break;
		}
		if(instruction == -1) return true;
		else if(instruction ==0) continue;
	}
	return false;
}

int checkAllclients(Agency& agency){

	std::cout << "Here are all the clients registered:\n" << std::endl;

	for(unsigned int i = 0; i < agency.getClients().size(); i++){
		std::cout << *agency.getClients().at(i) << std::endl;
	}

	return 0;
}

int addClient(Agency& agency){

	std::cout << "\n\tNew client:" <<std::endl;
	std::cout << "\n\t0 - Cancel\t -1 Exit Program" <<std::endl;
	std::cout << "\n\tPlease fill out this form in order to add a new client.\n" <<std::endl;

	std::string input;
	std::stringstream ss;

	std::cin.ignore();

	//Client name
	std::cout << "\tFull Name:";
	std::getline(std::cin, input);

	if(input == "-1") return -1;
	else if(input == "0") return 0;

	std::string name = input;

	input.clear();



	//NIF
	long int nif;
	std::cout << "\tNIF: ";
	std::cin >> nif;

	if(std::cin.fail()){
		std::cout << "Not a number.";
		return 0;
	}
	if(nif == -1) return -1;
	else if(nif == 0) return 0;

	input.clear();

	//EMAIL
	std::cout << "\tEmail: ";
	std::cin.ignore();
	std::getline(std::cin, input);

	if(input == "-1") return -1;
	else if(input == "0") return 0;

	std::string email = input;

	input.clear();

	Client* c = new Client(name, nif, email);
	agency.addClient(c);

	std::cout << "The client has been added." << std::endl;

	return 0;
}

int checkClient(Agency& agency){

	int id;

	std::cout << "\t 0 - Go Back" << std::endl;
	std::cout << "\t-1 - Exit Program\n" << std::endl;
	std::cout << "\t\tPlease enter the client's ID." <<std::endl;
	std::cout << "\t\tID: ";

	std::cin >> id;
	if(id == -1) return -1;
	if(id == 0) return 0;

	int index;
	index = binarySearchC(agency.getClients(), id);

	std::cout << *agency.getClients()[index] << std::endl;

	return 0;

}

//OPEN MAP INTERFACE

bool mapMenu(Agency& agency){
	int option;

	while(option != -1){
		std::cout <<"\n\tMAP:" << std::endl;
		std::cout << "\t1 - Open full map" << std::endl;
		std::cout << "\t0 - Go back" << std::endl;
		std::cout << "\t-1 - Exit program.\n" << std::endl;

		int instruction;

		std::cout << "\nPlease enter an option: ";
		std::cin >> option;

		switch(option){
		case 1:
			instruction = openMap(agency);
			break;
		case 0:
			return false;
		case -1:
			instruction = -1;
			break;
		default:
			std::cout << "\nPlease insert a valid option." << std::endl;
			break;
		}
		if(instruction == -1) return true;
		else if(instruction ==0) continue;
	}
	return false;
}


int openMap(Agency& agency){
	return 0;
}































//FLIGHT INTERFACE

bool flightMenu(Agency& agency){
	int option;

	while(option != -1){
		std::cout <<"\n\tMAP:\nWhat do you wish to optimize?" << std::endl;
		std::cout << "\t 1 - Time" << std::endl;
		std::cout << "\t 2 - Cost" << std::endl;
		std::cout << "\t 0 - Go back" << std::endl;
		std::cout << "\t-1 - Exit program.\n" << std::endl;

		int instruction;

		switch(option){
		case 1:
			//instruction = flightReservation1(agency);
			break;
		case 2:
			//instruction = flightReservation2(agency);
			break;
		case 0:
			return false;
		case -1:
			instruction = -1;
		default:
			std::cout << "Insert a valid option." << std::endl;
		}

		if(instruction == -1) return true;
		else if(instruction ==0) continue;
	}
	return false;
}

int flightReservation1(Agency& agency){
	return 0;
}
int flightReservation2(Agency& agency){
	return 0;
}



























//DESTINIES AVAILABLE INTERFACE

bool destiniesMenu(Agency& agency){
	int option;

	while(option != -1){
		std::cout <<"\n\tDESTINIES\n" << std::endl;
		std::cout << "\t1 - Check operating cities" << std::endl;
		std::cout << "\t2 - Check possible destinies from a city" << std::endl;

		std::cout << "\t0 - Go back" << std::endl;
		std::cout << "\t-1 - Exit program.\n" << std::endl;

		int instruction;

		std::cout << "\nPlease enter an option: ";
		std::cin >> option;

		switch(option){
		case 1:
			instruction = checkOperatingCities(agency);
			break;
		case 2:
			instruction = checkPossibleDestinies(agency);
			break;
		case 0:
			return false;
		case -1:
			instruction = -1;
			break;
		default:
			std::cout << "\nPlease insert a valid option." << std::endl;
			break;
		}
		if(instruction == -1) return true;
		else if(instruction ==0) continue;
	}
	return false;
}

int checkOperatingCities(Agency& agency){

	for(unsigned int i = 0; i < agency.getDestinies().size(); i++){
		std::cout << *agency.getDestinies()[i] << std::endl;
	}
	return 0;

}

int checkPossibleDestinies(Agency& agency){
	return 0;
}

