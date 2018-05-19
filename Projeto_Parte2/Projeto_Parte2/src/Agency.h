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
	/**
	 * @brief Variable that stores the agency's name
	 */
	std::string name;
	/**
	 * @brief Vector that stores the clients associated with the agency
	 */
	std::vector<Client*> clients;
	/**
	 * @brief Vector that stores the destinies (cities) that can be visited through the agency
	 */
	std::vector<Destiny> destinies; //Vector with operating cities
	/**
	 * @brief Graph that stores the destinies associated with the company and the relation between them
	 */
	Graph<Destiny> graph;
public:
	/**
	 * @brief Constructor for the Agency class that sets the name as the argument given
	 * @param name
	 */
	Agency(std::string name);

	/**
	 * @brief Gets the agency's name
	 * @return
	 */
	std::string getName() const;

	/**
	 * @brief Gets the current clients vector
	 * @return clients
	 */
	std::vector<Client*> getClients() const;

	/**
	 * @brief Gets the current destinies vector
	 * @return destinies
	 */
	std::vector<Destiny> getDestinies() const;

	/**
	 * @brief Gets the current destinies graph
	 * @return graph
	 */
	Graph<Destiny> getGraph() const;

	/**
	 * @brief Adds the client passed as an argument to the clients vector
	 * @param c
	 */
	void addClient(Client* c);

	/**
	 * @brief Adds the destiny passed as an argument to the destinies vector
	 * @param d
	 */
	void addDestiny(Destiny& d);

	/**
	 * @brief Adds the vertex with the information passed as an argument to the destinies graph
	 * @param d
	 */
	void addVertex(Destiny& d);

	/**
	 * @brief Adds the edge with the information passed as the arguments to te destinies graph
	 * @param origin
	 * @param dest
	 * @param cost
	 */
	void addEdge(Destiny& origin, Destiny& dest, double cost);

	/**
	 * @brief Calculates the shortest path between two cities
	 * @param origin
	 */
	void dijkstra(Destiny& origin);

	/**
	 * @brief Gets the shortest path between the two cities passes as arguments
	 * @param origin
	 * @param dest
	 * @return
	 */
	std::vector<Destiny> getPath(Destiny& origin, Destiny& dest);

	std::vector<std::string> numStringMatchingI(std::string toSearch);

	std::vector<std::string> numApproximateStringMatchingI(string toSearch);

	std::vector<std::string> numStringMatchingC(std::string toSearch);

	std::vector<std::string> numApproximateStringMatchingC(std::string toSearch);

	std::string findCityIP(std::string ip);
};



#endif /* AGENCY_H_ */
