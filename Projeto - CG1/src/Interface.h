/*
 * Interface.h
 *
 *  Created on: 29/03/2018
 *      Author: Jo
 */

#ifndef INTERFACE_H_
#define INTERFACE_H_
#include "Agency.h"

void initMenu(Agency& agency);
int showMenu(Agency& agency);
bool clientsMenu(Agency& agency);
bool showMap(Agency& agency);
bool flightMenu(Agency& agency);
bool destiniesMenu(Agency& agency);

int checkAllclients(Agency& agency);
int addClient(Agency& agency);
int checkClient(Agency& agency);

#endif /* INTERFACE_H_ */
