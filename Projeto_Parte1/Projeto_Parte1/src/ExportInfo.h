/*
 * ExportInfo.h
 *
 *  Created on: 30/03/2018
 *      Author: Jo
 */

#ifndef EXPORTINFO_H_
#define EXPORTINFO_H_

#include "Libraries.h"
#include "Agency.h"


/**
* @brief Exports the clients to a text file
* @param agency Agency with a vector of clients
*/
void exportClients(Agency& agency);

void exportInfoFlight1(int id, std::string accommodation, int cost, Destiny &d);

void exportInfoFlight2(int id, std::vector<Accommodation*> a, std::vector<string> stops, int cost);


#endif /* EXPORTINFO_H_ */
