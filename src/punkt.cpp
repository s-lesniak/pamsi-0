/*!
 * \file punkt.cpp
 *
 *  Created on: 31 maj 2014
 *      Author: szymon
 */

#include <iostream>
#include <sstream>
#include <string>

#include "punkt.hh"

using namespace std;

ostream& operator << (ostream& str, const Punkt &p)
{
	str << p.Nazwa << ": " << p.szer << ", " << p.dl << endl;

	return str;
}

istream& operator >> (istream& str, Punkt &p)
{
	string linijka; // długość napisu z zapasem na współrzędne geogr.
	getline(str, linijka);

	istringstream sstr(linijka);

	getline(sstr, p.Nazwa, ',');

	double a;
	sstr >> a;
	if ((a < -90) || (a > 90))
		throw zla_wspol();
	p.szer = a;

	sstr.ignore();
	sstr >> a;
	if ((a < -180) || (a > 180))
		throw zla_wspol();
	p.dl = a;

	return str;
}
