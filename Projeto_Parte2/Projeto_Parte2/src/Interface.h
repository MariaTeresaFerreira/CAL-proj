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
#include "graphviewer.h"

/**
 * @brief Handles the initial menu and calls the function selected
 * @param agency
 */
void initMenu(Agency& agency);

/**
 * @brief Prints the options available in the initial menu and handles the user input
 * @param agency
 * @return Number of the option selected by the user
 */
int showMenu(Agency& agency);

/**
 * @brief Prints the options available in the client's menu and handles the user input calling the function selected
 * @param agency
 * @return True or false if you want to exit or go back in the program, respectively
 */
bool clientsMenu(Agency& agency);


/**
 * @brief Prints the options available in the flights' menu and handles the user input calling the function selected
 * @param agency
 * @return True or false if you want to exit or go back in the program, respectively
 */
bool flightMenu(Agency& agency);

/**
 * @brief Prints the options available in the destinies' menu and handles the user input calling the function selected
 * @param agency
 * @return True or false if you want to exit or go back in the program, respectively
 */
bool destiniesMenu(Agency& agency);

/**
 * @brief Prints the options available in the map's menu and handles the user input calling the function selected
 * @param agency
 * @return True or false if you want to exit or go back in the program, respectively
 */
bool mapMenu(Agency& agency);

/**
 * @brief Prints the options available in the flight's menu and handles the user input calling the function selected
 * @param agency
 * @return True or false if you want to exit or go back in the program, respectively
 */
bool flightMenu(Agency& agency);


/**
 * @brief Opens the graph viewer
 * @param agency
 * @return 0 upon success
 */
int openMap(Agency& agency);

/**
 * @brief Updates the graph for the graph viewer
 * @param agency
 */
void updateMap(Agency& agency);

/**
 * @brief Opens the graph viewer for a specific route
 * @param d
 */
void openMapRoute(std::vector<Destiny> &d);

/**
 * @brief Closes the graph viewer window for the full map
 * @return 0 upon success
 */
int closeMap1();

/**
 * @brief Closes the graph viewer window for the one route map
 * @return 0 upon success
 */
int closeMap2();


/**
 * @brief Displays the information of all the clients
 * @param agency
 * @return 0 upon success
 */
int checkAllclients(Agency& agency);

/**
 * @brief Enables the user to add a new client
 * @param agency
 * @return 0 upon success
 */
int addClient(Agency& agency);

/**
 * @brief Displays the information of the specific client whose ID was inserted by the user
 * @param agency
 * @return 0 upon success
 */
int checkClient(Agency& agency);


/**
 * @brief Handles the first way to book a flight (optimization based on time)
 * @param agency
 * @return 0 upon success
 */
int flightReservation1(Agency& agency);

/**
 * @brief Handles the second way to book a flight (optimization based on price)
 * @param agency
 * @return 0 upon success
 */
int flightReservation2(Agency& agency);

/**
 * @brief Handles the third way to book a flight (optimization based on price, but with dates constraint)
 * @param agency
 * @return 0 upon success
 */
int flightReservation3(Agency& agency);

/**
 * @brief Handles the option of a client wanting to visit more than one city
 * @param agency
 * @return 0 upon success
 */
int manyDestinies(Agency& agency);

/**
 * @brief Gets the time of the trip
 * @param d
 * @param id
 * @return 0 upon success
 */
int getTime(Destiny &d, int id);

/**
 * @brief Gets the cost of the trip
 * @param d
 * @param id
 * @return 0 upon success
 */
int getCost(Destiny &d, int id);

/**
 * @brief Displays all the destinies
 * @param agency
 * @return 0 upon success
 */
int checkOperatingCities(Agency& agency);

/**
 * @brief Displays all the destiny options from the origin inserted by the user
 * @param agency
 * @return 0 upon success
 */
int checkPossibleDestinies(Agency& agency);

/**
 * @brief Displays all the accommodation options from the origin inserted by the user
 * @param agency
 * @return 0 upon success
 */
int checkAccommodations(Agency& agency);

/**
 * @brief Checks if there are no date problems based on the third method to book a flight
 * @param dates
 * @param days
 * @return true
 */
bool checkDays(std::vector<Date> &dates, int days);

std::string tryApproximateC(std::string origin, Agency& agency);

std::string tryApproximateI(std::string origin, Agency& agency);

#endif /* INTERFACE_H_ */
