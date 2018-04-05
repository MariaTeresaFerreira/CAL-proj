/*
 * Interface.cpp
 *
 *  Created on: 29/03/2018
 *      Author: Jo
 */
#include "Libraries.h"
#include "Interface.h"

GraphViewer *gv;

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
	std::cout << "Please insert a valid option:";

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


/*
 * Menu to open our map. INACABADO, depende dos ficheiros de texto.
 */

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

	std::cout << "\t Opening our map . . . " << std::endl;

	gv->setBackground("background_small.jpg");
	gv->createWindow(1280, 835); //mudar conforme resolução da imagem.
	gv->defineVertexColor("red");
	gv->defineEdgeColor("red");

	updateMap(agency);

	return false;
}

void updateMap(Agency& agency){ //FUNÇÃO QUE USO PARA CONSTRUIR O GRAPHO, graphviewer
	int id, coordx, coordy;
	std::string name;

	for(size_t i = 0; i < agency.getDestinies().size(); i++){
		id = agency.getDestinies()[i].getID();
		coordx = agency.getDestinies()[i].getCoord().getX();
		coordy = agency.getDestinies()[i].getCoord().getY();
		name = agency.getDestinies()[i].getCityName();

		gv->addNode(id, coordx, coordy);
		gv->setVertexLabel(id, name);
		gv->setVertexColor(id, "red");
		gv->setVertexSize(id, 15);
		gv->defineEdgeCurved(false);
	}
	 int idDest = 0;

	 for(size_t i = 0; i < agency.getDestinies().size(); i++){

			 for(size_t k = 0; k < agency.getDestinies()[i].getNumberOfDest(); k++){

				 int destinyID = agency.getDestinies()[i].getAllDestinies()[k]->getID();
				 gv->addEdge(idDest, agency.getDestinies()[i].getID(), destinyID, EdgeType::DIRECTED);

				 idDest++;
			 }
	 }

	gv->rearrange();
}




/*
 * Menu where the clients will be able to get their reservation
 */

bool flightMenu(Agency& agency){
	int option;

	while(option != -1){
		std::cout <<"\n\tMAP:\nWhat do you wish to optimize?" << std::endl;
		std::cout << "\t 1 - Time" << std::endl;
		std::cout << "\t 2 - Cost" << std::endl;
		std::cout << "\t 0 - Go back" << std::endl;
		std::cout << "\t-1 - Exit program.\n" << std::endl;

		int instruction;

		std::cout << "\nPlease enter an option: ";
		std::cin >> option;

		switch(option){
		case 1:
			instruction = flightReservation1(agency);
			break;
		case 2:
			instruction = flightReservation2(agency);
			break;
		case 0:
			return false;
		case -1:
			instruction = -1;
			break;
		default:
			std::cout << "Insert a valid option." << std::endl;
		}

		if(instruction == -1) return true;
		else if(instruction ==0) continue;
	}
	return false;
}

int flightReservation1(Agency& agency){
	std::string origin, destiny, option;
	std::vector<std::string> stops;

	loadEdgesTime(agency);

	std::cout << "Do you wish to visit more than one city?[y/n]";
	std::cin >> option;

	if(option == "yes" || option == "y" || option == "YES" || option == "Y") return 0;//adicionar função para vários destinos.

	//PARTIDA
	std::cout << "Please insert the city where you want to begin your travel:";
	std::cout << std::endl;
	std::cin >> origin;

	//CHEGADA
	std::cout << "Please insert the city where you want to end your travel:";
	std::cout << std::endl;
	std::cin >> destiny;
	std::cout << "\n\n\n\n";

	//RESGISTAR PARTIDA E CHEGADA PARA MAIS TARDE VER SE É POSSÍVEL.
	Destiny init = searchCityName(agency.getDestinies(), origin);
	Destiny dest = searchCityName(agency.getDestinies(), destiny);

	agency.dijkstra(init);
	std::vector<Destiny> d = agency.getPath(init, dest);

	//Falta adicionar a opção de o sítio não ser atingível.
	if(d.size() > 2){
		std::cout << "We couldn't find a direct flight, so we chose this route in order to optimize your time!\n" << std::endl;
		for(size_t i = 0; i < d.size(); i++){
			if(i == d.size() -1){
				std::cout << d[i].getCityName() << std::endl;
			}else{
				std::cout << d[i].getCityName() << "---->"; //Se houver tempo, mudar isto para uma representação no graphviewer
			}
		}
	}


	//ACCOMMODATION

	std::cout << "Now pick one of the accommodations available at the chosen destiny:\n\n " << std::endl;

	for(size_t i = 0; i < dest.getAllAccommodation().size(); i++){
		std::cout << *dest.getAllAccommodation()[i];
	}

	std::string accommodation;
	std::cout << "Choose one:";
	std::cout << std::endl;
	std::cin.ignore();
	std::getline(std::cin, accommodation);

	Accommodation *acc = dest.findByName(accommodation);
	//std::cout << *acc << std::endl;

	//DATE

	int dayI, monthI, dayE, monthE;

	std::cout << "Now insert the date. . . " << std::endl;

	std::cout << "Departure day: ";
	std::cin >> dayI;
	std::cout << std::endl;

	std::cout << "Departure month: ";
	std::cin >> monthI;
	std::cout << std::endl;

	std::cout << "Returning day: ";
	std::cin >> dayE;
	std::cout << std::endl;

	std::cout << "Returning month: ";
	std::cin >> monthE;
	std::cout << std::endl;

	Date dateInit = Date(dayI, monthI);
	Date dateEnd = Date(dayE, monthE);

	int cost = acc->getPrice(dateInit);

	std::cout << "Your accommodation will cost :" << cost << " euros" << std::endl;
	//DONE AGORA É SO ACABAR AS OUTRAS E SE ME DER NOS CORNOS FAÇO UMA CLASSE RESERVAS

	//openMapRoute(d);

	return 0;
}

int flightReservation2(Agency& agency){

	std::string origin, destiny, option;
	std::vector<std::string> stops;

	loadEdgesCost(agency);

	std::cout << "Do you wish to visit more than one city?[y/n]";
	std::cin >> option;

	if(option == "yes" || option == "y" || option == "YES" || option == "Y") return 0;//adicionar função para vários destinos.

	//PARTIDA
	std::cout << "Please insert the city where you want to begin your travel:";
	std::cout << std::endl;
	std::cin >> origin;

	//CHEGADA
	std::cout << "Please insert the city where you want to end your travel:";
	std::cout << std::endl;
	std::cin >> destiny;
	std::cout << "\n\n";

	//RESGISTAR PARTIDA E CHEGADA PARA MAIS TARDE VER SE É POSSÍVEL.
	Destiny init = searchCityName(agency.getDestinies(), origin);
	Destiny dest = searchCityName(agency.getDestinies(), destiny);

	agency.dijkstra(init);
	std::vector<Destiny> d = agency.getPath(init, dest);

	//Falta adicionar a opção de o sítio não ser atingível.
	if(d.size() > 2){
		std::cout << "In order to optimize the cost, we have chosen this route: \n" << std::endl;
		for(size_t i = 0; i < d.size(); i++){
			if(i == d.size() -1){
				std::cout << d[i].getCityName() << std::endl;
			}else{
				std::cout << d[i].getCityName() << "---->"; //Se houver tempo, mudar isto para uma representação no graphviewer
			}
		}
	}
	std::cout << std::endl;
	//DATE
	int dayI, monthI, dayE, monthE;

	std::cout << "Now insert the date. . . " << std::endl;

	std::cout << "Departure day: ";
	std::cin >> dayI;
	std::cout << std::endl;

	std::cout << "Departure month: ";
	std::cin >> monthI;
	std::cout << std::endl;

	std::cout << "Returning day: ";
	std::cin >> dayE;
	std::cout << std::endl;

	std::cout << "Returning month: ";
	std::cin >> monthE;
	std::cout << std::endl;

	Date dateInit = Date(dayI, monthI);
	Date dateEnd = Date(dayE, monthE);

	//CHEAPEST ACCOMMODATION
	Accommodation *acc = dest.cheapestAccommodation(dateInit);

	std::cout << "In order to optimize the cost, we have chosen this accommodation: \n";
	std::cout << *acc << std::endl;

	int cost = acc->getPrice(dateInit);

	std::cout << "The accommodation will cost you " << cost << " euros" << std::endl;

	//openMapRoute(d);

	return 0;
}

/*
 * Here we have the functions that let the client know the destinies they can travel to, the cost of the flight and the time spent.
 */

bool destiniesMenu(Agency& agency){
	int option;

	while(option != -1){
		std::cout <<"\n\tDESTINIES\n" << std::endl;
		std::cout << "\t1 - Check operating cities" << std::endl;
		std::cout << "\t2 - Check possible destinies from a city" << std::endl;
		std::cout << "\t3 - Check the accommodations available" << std::endl;

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
		case 3:
			instruction = checkAccommodations(agency);
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

	std::cout << "These are the Cities that have our services:" << std::endl;

	for(unsigned int i = 0; i < agency.getDestinies().size(); i++){
		std::cout << agency.getDestinies()[i] << std::endl;
	}
	return 0;

}

int checkPossibleDestinies(Agency& agency){

	std::string city;

	std::cout << "Please enter the city where you will start your travel: " << std::endl;
	std::cin >> city;
	if(city == "0") return 0;
	if(city == "-1") return -1;

	int index;

	for(unsigned int j = 0; j < agency.getDestinies().size(); j++){
		if(agency.getDestinies()[j].getCityName() == city){
			index = j;
			break;
		}
	}

	unsigned int size = agency.getDestinies()[index].getAllDestinies().size();

	for(unsigned int i = 0; i < size; i++){
		std::cout << *agency.getDestinies()[index].getAllDestinies()[i] << std::endl;
	}
	return 0;
}

int checkAccommodations(Agency& agency){
	std::string city;
	std::cout << "Please enter the name of the city you wish to search for accommodations: " << std::endl;
	std::cin >> city;
	if(city == "0") return 0;
	if(city == "-1") return -1;

	int index;

	for(unsigned int j = 0; j < agency.getDestinies().size(); j++){
		if(agency.getDestinies()[j].getCityName() == city){
			index = j;
			break;
		}
	}

	for(unsigned int i = 0; i < agency.getDestinies()[index].getAllAccommodation().size(); i++){
		std::cout << *agency.getDestinies()[index].getAllAccommodation()[i] << std::endl;
	}

	return 0;
}

/*
 * Main function, calls the import files functions and prepares
 * the structure.
 */



void import_info(Agency& agency){
	importClients(agency);
	importCities(agency);
}

void export_info(Agency& agency){
	exportClients(agency);
	std::cout << "Program terminated, we wish you a good trip.\t" << std::endl;
}

int main(){

	Agency agency("MIEIC FlightAgency");

	std::cout << "Welcome to MIEIC flight agency!\n" << std::endl;

	gv = new GraphViewer(1280, 835, false); //mudar conforme resolução da imagem
	import_info(agency);
	initMenu(agency);
	export_info(agency);

	return 0;
}
