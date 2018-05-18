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

/**
* @brief Exports the reservation in flightReservation1 to a text file
* @param id ID of the client
* @param accommodation Accommodation where the client will be staying
* @param cost total cost for the travel with accommodation/s
* @param d destiny of the flight
*/
void exportInfoFlight1(int id, std::string accommodation, int cost, Destiny &d);

/**
* @brief Exports the reservation in flightReservation2 and 3 to a text file
* @param id ID of the client
* @param a Vector of accommodations where the client will be staying
* @param stops Vector with the name of the cities the client will visit
* @param cost Total cost for the flights and accommodations
*/
void exportInfoFlight2(int id, std::vector<Accommodation*> a, std::vector<string> stops, int cost);


#endif /* EXPORTINFO_H_ */
