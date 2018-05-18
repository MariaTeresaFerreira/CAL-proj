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

Destiny Agency::numStringMatchingI(std::string toSearch){
	int found = 0;
	for(auto v : graph.getVertexSet()){
		for(int i = 0; i < v->getInfo().getInterestPoints().size(); i++){

			found = kmpMatcher(v->getInfo().getInterestPoints()[i], toSearch);
			if(found == 1) return v->getInfo();

		}
	}

	Destiny nonExistant;
	return nonExistant;
}

Destiny Agency::numStringMatchingC(std::string toSearch){
	int found = 0;
	for(auto v : graph.getVertexSet()){
		found = kmpMatcher(v->getInfo().getCityName(), toSearch);
		if(found == 1) return v->getInfo();
	}

	Destiny nonExistant;
	return nonExistant;
}
/*

float Agency::numApproximateStringMatchingI(Graph<Destiny> graph,string toSearch) {
	int counter = 0, n = 0;

	for(auto v : graph.vertexSet){
		for(int i = 0; i < v->getInfo().getInterestPoints().size(); i++){
			counter += editDistance(v->getInfo().getInterestPoints()[i], toSearch);
			n++;
		}
	}
	return (float)counter/n;
}

float Agency::numApproximateStringMatchingC(Graph<Destiny> graph, string toSearch){
	int counter = 0, n = 0;

	for(auto v : graph.vertexSet){
		counter += editDistance(v->getInfo().getCityName(), toSearch);
		n++;
	}
	return (float)counter/n;
}
*/

