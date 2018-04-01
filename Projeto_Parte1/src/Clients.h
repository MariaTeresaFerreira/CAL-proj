/*
 * Clients.h
 *
 *  Created on: 30/03/2018
 *      Author: Jo
 */

#ifndef CLIENTS_H_
#define CLIENTS_H_

#include "Libraries.h"
#include "Destiny.h"

class Client{
	static int ultID;
	int id;
	std::string name;
	unsigned long NIF;
	std::string email;
	//Destiny initCity;
public:

	Client(std::string name, unsigned long NIF, std::string email);
	Client(int id, std::string name, unsigned long NIF, std::string email);
	int getID() const;
	std::string getName() const;
	unsigned long getNIF() const;
	std::string getEmail() const;

	void setName(std::string nome);
	void setNIF(unsigned long nif);
	void setEmail(std::string email);

	friend std::ostream & operator <<(std::ostream &o, const Client & p){
		o << "Name: " << p.getName() << std::endl;
		o << "ID: " << p.getID() << std::endl;
		o << "Email: " << p.getEmail() << std::endl;
		return o;
	}
};

#endif /* CLIENTS_H_ */
