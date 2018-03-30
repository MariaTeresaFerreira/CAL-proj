/*
 * Agency.h
 *
 *  Created on: 30/03/2018
 *      Author: Jo
 */

#ifndef AGENCY_H_
#define AGENCY_H_
#include "Libraries.h"
#include "Algorithms.h"
#include "Clients.h"
#include "Destiny.h"

class Agency{
	std::string name;
	std::vector<Client*> clients;
	std::vector<Destiny*> destinies; //Vector with operating cities
public:
	Agency(std::string name);
	std::string getName() const;
	std::vector<Client*> getClients() const;
	std::vector<Destiny*> getDestinies() const;

	void addClient(Client* c);
};



#endif /* AGENCY_H_ */
