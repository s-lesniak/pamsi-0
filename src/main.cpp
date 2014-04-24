/*! @file main.cpp
 * @brief Główny plik programu */

#include <string>
#include <iostream>
#include <cstdlib>

#include "graf.hh"
#include "macierz.hh"

using namespace std;
 
int main ()
{
	Macierz<double> przykl(8);

	przykl(2, 3) = 9.3;
	cout << przykl(2,3) << endl;

	przykl.Usun(2);
	cout << przykl(2,3);

	return 0;
}
