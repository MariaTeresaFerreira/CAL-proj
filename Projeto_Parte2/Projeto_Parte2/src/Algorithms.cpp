/*
 * Algorithms.c
 *
 *  Created on: 23/03/2018
 *      Author:Francisco Miranda; João Vaz Gama Amaral; Maria Teresa Ferreira;
 */
#include "Algorithms.h"

void bubbleSortD(std::vector<Destiny> destiny_aux){
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

void bubbleSortDname(std::vector<Destiny> destiny_aux){
	for(unsigned int j = destiny_aux.size()-1; j > 0; j--){
		bool change = false;
		for(unsigned int i = 0; i < j; i++)
			if(destiny_aux[i+1].getCityName() < destiny_aux[i].getCityName()){
				std::swap(destiny_aux[i], destiny_aux[i+1]);
				change = true;
			}
		if (!change) return;
	}
}

void selectionSortD(std::vector<Destiny> &d_aux){
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

int binarySearchC(const std::vector<Client*> &v, int x)
{
	int left = 0, right = v.size() - 1;

	while (left <= right)
	{
		int middle = (left + right) / 2;

		if (v[middle]->getID() < x)
			left = middle + 1;
		else if (x < v[middle]->getID())
			right = middle-1;
		else
			return middle;
	}
	return -1;
}

int binarySearchC(const std::vector<Client*> &v, std::string x)
{
	int left = 0, right = v.size() - 1;

	while (left <= right)
	{
		int middle = (left + right) / 2;

		if (v[middle]->getName() < x)
			left = middle + 1;
		else if (x < v[middle]->getName())
			right = middle-1;
		else
			return middle;
	}
	return -1;
}

Destiny searchID(std::vector<Destiny> vect, int ID){
	int inf = 0;
	int sup = vect.size() -1;
	int middle;
	while(vect[inf].getID() <= vect[sup].getID()){
		middle = floor((inf+sup)/2);
		if(ID == vect[middle].getID())
			return vect[middle];
		if(ID < vect[middle].getID())
			sup = middle-1;
		else
			inf = middle + 1;
	}
	return Destiny();
}

Destiny binarySearchD(const std::vector<Destiny> d, std::string x)
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
			return d[middle];
	}
	return Destiny();
}

Destiny searchCityName(const std::vector<Destiny> d, std::string x){
	for(size_t i = 0; i < d.size(); i++){
		if(d[i].getCityName() == x)
			return d[i];
	}
	return Destiny();
}

bool isPossibleDestiny(const std::vector<PossibleDestinies*> p, Destiny d){
	for(size_t i = 0; i < p.size(); i++){
		if(p[i]->getID() == d.getID()){
			return true;
		}
	}
	return false;
}

std::vector<int> preKMP(string pattern){
	int m = pattern.length();
	vector<int> prefix(m);
	prefix[0] = -1;
	int k = -1;
	for(int q = 1; q < m; q++){
		while(k > -1 && pattern[k+1] != pattern[q]) {
			k = prefix[k];
		}
		if(pattern[k+1] == pattern[q])
			k = k+1;
		prefix[q] = k;
	}
	return prefix;
}

int kmpMatcher(string text, string pattern) {
	int num = 0;
		int n = text.length();
		int m = pattern.length();
		vector<int> prefix = preKMP(pattern);
		int q = -1;
		for(int i = 0; i < n; i++){
			while(q > -1 && pattern[q+1]!=text[i])
				q = prefix[q];
			if(pattern[q+1] == text[i])
				q++;
			if(q == m-1){
				num++;
				q = prefix[q];
			}
		}
		return num;
}

int editDistance(string pattern, string text) {

	int n = text.length();
    int m = pattern.length();
    int previous, next;
    int d[n+1];

    for (int j = 0; j < n + 1; j++)
        d[j] = j;

    for (int i = 1; i < m + 1; i++)
    {
        previous = d[0];
        d[0] = i;
        for (int j = 1; j < n + 1 ; j++)
        {
            if (pattern[i - 1] == text[j - 1])
                next = previous;
            else
            {
                next = min(previous, d[j]);
                next = 1 + min(next, d[j-1]);
            }
            previous = d[j];
            d[j] = next;
        }
    }
    return d[n];
}









