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

	/**
	 * @brief Variable that stores the last ID used to specify a client
	 */
	static int ultID;

	/**
	 * @brief Variable that stores the client's ID
	 */
	int id;

	/**
	 * @brief Variable that stores the client's name
	 */
	std::string name;

	/**
	 * @brief Variable that stores the client's NIF
	 */
	unsigned long NIF;

	/**
	 * @brief Variable that stores the client's email address
	 */
	std::string email;
	//Destiny initCity;
public:

	/**
	 * @brief Constructor for the Clients class that sets the name, the NIF, and the email address to the received arguments
	 * @param name
	 * @param NIF
	 * @param email
	 */
	Client(std::string name, unsigned long NIF, std::string email);

	/**
	 * @brief Constructor for the Clients class that sets the id, the name, the NIF, and the email address to the received arguments
	 * @param id
	 * @param name
	 * @param NIF
	 * @param email
	 */
	Client(int id, std::string name, unsigned long NIF, std::string email);

	/**
	 * @brief Gets the client's ID
	 * @return id
	 */
	int getID() const;

	/**
	 * @brief Gets the client's name
	 * @return name
	 */
	std::string getName() const;

	/**
	 * @brief Gets the client's NIF
	 * @return NIF
	 */
	unsigned long getNIF() const;

	/**
	 * @brief Gets the client's email address
	 * @return email
	 */
	std::string getEmail() const;


	/**
	 * @brief Sets the client's name to the name passed as an argument
	 * @param nome
	 */
	void setName(std::string nome);

	/**
	 * @brief Sets the client's NIF to the NIF passed as an argument
	 * @param nif
	 */
	void setNIF(unsigned long nif);

	/**
	 * @brief Sets the client's email to the email address passed as an argument
	 * @param email
	 */
	void setEmail(std::string email);

	/**
	 * @brief Overloading of the << operator in order to present the information in a user friendly way
	 * @param o
	 * @param p
	 * @return ostream
	 */
	friend std::ostream & operator <<(std::ostream &o, const Client & p){
		o << "Name: " << p.getName() << std::endl;
		o << "ID: " << p.getID() << std::endl;
		o << "Email: " << p.getEmail() << std::endl;
		return o;
	}
};

#endif /* CLIENTS_H_ */
