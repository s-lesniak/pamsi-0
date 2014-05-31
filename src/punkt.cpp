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

extern const unsigned MAX_DL;

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

	sstr >> p.szer;
	sstr.ignore();
	sstr >> p.dl;

	return str;
}
