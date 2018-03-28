/*
 * Algorithms.h
 *
 *  Created on: 23/03/2018
 *      Author: Francisco Miranda; João Vaz Gama Amaral; Maria Teresa Ferreira;
 */

#ifndef SRC_ALGORITHMS_H_
#define SRC_ALGORITHMS_H_

#include "Libraries.h"
#include "Destiny.h"
/*
 * @brief Bubble sort algorthm to sort a "Destiny" vector by ID
 * @param destiny_aux destiny vector to be sorted
 */
void bubbleSort(std::vector<Destiny*>& destiny_aux);

/*
 * @brief Selection sort to sort a Destiny vector by name
 * @param d_aux destiny vector to be sorted
 */
void selectionSort(std::vector<Destiny*> &d_aux);

/*
 * @brief Binary search algorithm to search a destiny by ID
 * @param d destiny vector to search
 * @param x destiny ID
 */
int binarySearch(const std::vector<Destiny*> &d, int x);

/*
 * @brief Binary search algorithm to search a destiny by name
 * @param d destinies vector to search
 * @param x destiny name
 */
int binarySearch(const std::vector<Destiny*> &d, std::string x);

#endif /* SRC_ALGORITHMS_H_ */
