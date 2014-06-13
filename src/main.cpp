/*! @file main.cpp
 * @brief Główny plik programu */

#include <string>
#include <iostream>
#include <cstdlib>
#include <exception>
#include <limits>

#include "eksperyment.hh"

using namespace std;

int main ()
{
	string wyj;
	cout << "Podaj nazwę pliku wyjściowego: ";
	cin >> wyj;
	try {
		Eksperyment ten_jedyny(wyj);
	}
	catch (const exception& e) {
		cerr << e.what();
	}
//
//	string a;
//	getline (cin, a);
//	cout << a << endl;
	return 0;
}
