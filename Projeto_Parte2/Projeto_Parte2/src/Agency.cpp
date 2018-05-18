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

//Algoritmos de procura aproximada.

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

std::vector<std::string> Agency::numApproximateStringMatchingI(string toSearch) {
	int counter = 0, n = 0;
	float charChange, compare;
	std::vector<std::string> found;

	for(auto v : graph.getVertexSet()){
		for(unsigned int i = 0; i < v->getInfo().getInterestPoints().size(); i++){

			counter = editDistance(v->getInfo().getInterestPoints()[i], toSearch);
			n++;

			charChange = (float)counter/n;
			compare = 0.7*(v->getInfo().getInterestPoints()[i].length());

			if(charChange < compare){
				found.push_back(v->getInfo().getInterestPoints()[i]);
			}

			n = 0;
		}
	}
	return found;
}


std::vector<std::string> Agency::numApproximateStringMatchingC(string toSearch){
	int counter = 0, n = 0;
	float charChange, compare;
	std::vector<std::string> found;

	for(auto v : graph.getVertexSet()){
		counter = editDistance(v->getInfo().getCityName(), toSearch);
		n++;
		charChange = (float)counter/n;
		compare = 0.7*(v->getInfo().getCityName().length());

		if(charChange < compare){
			found.push_back(v->getInfo().getCityName());
		}

		n = 0;
	}

	return found;
}


