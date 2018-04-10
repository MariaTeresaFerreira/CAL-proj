/*
 * Agency.cpp
 *
 *  Created on: 30/03/2018
 *      Author: Jo
 */
#include "Agency.h"

Agency::Agency(std::string name){
	this->name = name;
}

std::string Agency::getName() const{
	return this->name;
}

std::vector<Client*> Agency::getClients() const{
	return this->clients;
}

std::vector<Destiny> Agency::getDestinies() const{
	return this->destinies;
}

void Agency::addClient(Client* c){
	this->clients.push_back(c);
}

void Agency::addDestiny(Destiny &d){
	this->destinies.push_back(d);
}

Graph<Destiny> Agency::getGraph() const{
	return this->graph;
}

void Agency::addVertex(Destiny& d){
	this->graph.addVertex(d);
}

void Agency::addEdge(Destiny& origin, Destiny& dest, double cost){
	this->graph.addEdge(origin, dest, cost);
}

void Agency::dijkstra(Destiny& origin){
	this->graph.dijkstraShortestPath(origin);
}

vector<Destiny> Agency::getPath(Destiny& origin, Destiny& dest){
	return this->graph.getPath(origin, dest);
}
