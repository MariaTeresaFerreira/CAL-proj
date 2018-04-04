/*
 * Interface.h
 *
 *  Created on: 29/03/2018
 *      Author: Jo
 */

#ifndef INTERFACE_H_
#define INTERFACE_H_
#include "Agency.h"
#include "Libraries.h"
#include "ImportInfo.h"
#include "ExportInfo.h"


void initMenu(Agency& agency);
int showMenu(Agency& agency);
bool clientsMenu(Agency& agency);
bool showMap(Agency& agency);
bool flightMenu(Agency& agency);
bool destiniesMenu(Agency& agency);
bool mapMenu(Agency& agency);
bool flightMenu(Agency& agency);


int openMap(Agency& agency);
void updateMap(Agency& agency);


int checkAllclients(Agency& agency);
int addClient(Agency& agency);
int checkClient(Agency& agency);


int flightReservation1(Agency& agency);
int flightReservation2(Agency& agency);


int checkOperatingCities(Agency& agency);
int checkPossibleDestinies(Agency& agency);
int checkAccommodations(Agency& agency);

#endif /* INTERFACE_H_ */
