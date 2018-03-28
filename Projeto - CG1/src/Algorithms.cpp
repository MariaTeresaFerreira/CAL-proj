/*
 * Algorithms.c
 *
 *  Created on: 23/03/2018
 *      Author:Francisco Miranda; João Vaz Gama Amaral; Maria Teresa Ferreira;
 */
#include "Algorithms.h"

void bubbleSort(std::vector<Destiny>& destiny_aux){
	for(unsigned int j = destiny_aux.size()-1; j > 0; j--){
		bool change = false;
		for(unsigned int i = 0; i < j; i++)
			if(destiny_aux[i+1].getID() < destiny_aux[i].getID()){
				std::swap(destiny_aux[i], destiny_aux[i+1]);
				change = true;
			}
		if (!change) return;
	}
}

void selectionSort(std::vector<Destiny> &d_aux){
	unsigned int j, i;
	std::vector<Destiny*>::iterator it;

	for(i = 0; i < d_aux.size(); i++){

			for(j = i+1; j < d_aux.size(); j++){
					if(d_aux[j].getCityName() < d_aux[i].getCityName()){
						Destiny d = d_aux[i];
						d_aux[i] = d_aux[j];
						d_aux[j] = d;
					}
			}
	}
}

int binarySearch(const std::vector<Destiny> &d, int x)
{
	int left = 0, right = d.size() - 1;

	while (left <= right)
	{
		int middle = (left + right) / 2;

		if (d[middle].getID() < x)
			left = middle + 1;
		else if (x < d[middle].getID())
			right = middle-1;
		else
			return middle;
	}
	return -1;
}

int binarySearch(const std::vector<Destiny> &d, std::string x)
{
	int left = 0, right = d.size() - 1;

	while (left <= right)
	{
		int middle = (left + right) / 2;

		if (d[middle].getCityName() < x)
			left = middle + 1;
		else if (x < d[middle].getCityName())
			right = middle-1;
		else
			return middle;
	}
	return -1;
}
