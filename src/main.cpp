/*! @file main.cpp
 * @brief Główny plik programu */

#include <string>
#include <iostream>
#include <cstdlib>
#include <stdexcept>

#include "tahasz.hh"

using namespace std;
 
int main ()
{
	TAHasz<int, double> slownik(200);

	slownik[10] = 4.7;
	slownik[9] = 5.13;
	cout << slownik.Usun(9) << ' ';

	cout << slownik[9];
	return 0;
}
