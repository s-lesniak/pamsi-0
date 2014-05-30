/*! @file main.cpp
 * @brief Główny plik programu */

#include <string>
#include <iostream>
#include <cstdlib>
#include <stdexcept>

#include "punkt.hh"

using namespace std;

int main ()
{
	Punkt kamyk = {"Kamień Pomorski", 53.969722, 14.785833},
			wro = {"Wrocław", 51.11, 17.022222};

	cout << kamyk.OdlegloscDo(wro);
	return 0;
}
