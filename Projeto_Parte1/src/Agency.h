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
#include "graphviewer.h"
#include "Graph.h"
#include "connection.h"
#include "edgetype.h"

class Agency{
	std::string name;
	std::vector<Client*> clients;
	std::vector<Destiny> destinies; //Vector with operating cities
	Graph<Destiny> graph;
public:
	Agency(std::string name);
	std::string getName() const;
	std::vector<Client*> getClients() const;
	std::vector<Destiny> getDestinies() const;
	Graph<Destiny> getGraph() const;

	void addClient(Client* c);
	void addDestiny(Destiny& d);
};



#endif /* AGENCY_H_ */
