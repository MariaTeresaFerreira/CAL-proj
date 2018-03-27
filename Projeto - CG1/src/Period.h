/*
 * Period.h
 *
 *  Created on: 23/03/2018
 *      Author: Francisco Miranda; Jo�o Vaz Gama Amaral; Maria Teresa Ferreira;
 */

#ifndef SRC_PERIOD_H_
#define SRC_PERIOD_H_

class Period{
	Date init;
	Date end;
	float price;
	string festivity; // easter, christmas, ...
	string season; // winter, spring, summer,  autumn

public:
	Period(Date i, Date e, float p, string f, string s);
	Period(Date i, Date e, float p, string s);
	getInit() const;
	getEnd() const;
	getPrice() const;
	getFestivity() const;
	getSeason() const;
	setInit(Date d);
	setEnd(Date d);
	setPrice(float p);
	setFestivity(string f);
	setSeason(string s);
};



#endif /* SRC_PERIOD_H_ */
