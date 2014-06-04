/*! @file main.cpp
 * @brief Główny plik programu */

#include <string>
#include <iostream>
#include <cstdlib>
#include <exception>

#include "punkt.hh"

using namespace std;

int main ()
{
	Punkt test;

	try {
		cin >> test;
		cout << test;
	}
	catch (const exception &e) {
		cout << e.what();
	}

	return 0;
}
