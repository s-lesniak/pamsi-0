/*! @file main.cpp
 * @brief Główny plik programu */

#include <string>
#include <iostream>
#include <cstdlib>
#include <stdexcept>

#include "eksperyment.hh"
#include "graf.hh"

using namespace std;

int main ()
{
	char nazwa[20];
	cout << "Podaj nazwę pliku wyjściowego: ";
	cin >> nazwa;

	try {
		Eksperyment eks(nazwa);
	}
	catch (const exception& ex) {
		cout << ex.what();
	}
	return 0;
}
