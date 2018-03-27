/*
 * Accommodation.h
 *
 *  Created on: 23/03/2018
 *      Author: Francisco Miranda; João Vaz Gama Amaral; Maria Teresa Ferreira;
 */

#ifndef SRC_ACCOMMODATION_H_
#define SRC_ACCOMMODATION_H_

class Accommodation{
private:
	string name;
	vector<int> prices;
	//vetor com as epocas diferentes para atribuir preço
public:
	Accomodation(string name, vector<int> prices);

	string getName();
	vector getPrices();

	void setName(string name);
	void setPrice(int position, int price);

};


#endif /* SRC_ACCOMMODATION_H_ */
