/*
 * ImportInfo.h
 *
 *  Created on: 30/03/2018
 *      Author: Jo
 */

#ifndef IMPORTINFO_H_
#define IMPORTINFO_H_
#include "Libraries.h"
#include "Algorithms.h"
#include "Interface.h"
#include "Graph.h"
#include "graphviewer.h"

/**
* @brief Imports clients
* @param agency Parameter to import the information
*/
void importClients(Agency& agency);

/**
* @brief Imports cities
* @param agency Parameter to import the information
*/
void importCities(Agency& agency);

/**
* @brief Imports travels time to the edges
* @param agency Parameter to import the information
*/
void loadEdgesTime(Agency& agency);

/**
* @brief Imports cost of the flights to the edges
* @param agency Parameter to import the information
*/
void loadEdgesCost(Agency& agency);

#endif /* IMPORTINFO_H_ */
