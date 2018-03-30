/*
 * main.cpp
 *
 *  Created on: 29/03/2018
 *      Author: Jo
 */

#include "Libraries.h"
#include "Interface.h"
#include "ImportInfo.h"
#include "ExportInfo.h"

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

	//gv = new GraphViewer(1680, 1050, "");
	import_info(agency);
	initMenu(agency);
	export_info(agency);
	//gv->closeWindow();

	return 0;
}
