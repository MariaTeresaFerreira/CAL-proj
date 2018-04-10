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

void importClients(Agency& agency);

void importCities(Agency& agency);

void loadEdgesTime(Agency& agency);

void loadEdgesCost(Agency& agency);

#endif /* IMPORTINFO_H_ */
