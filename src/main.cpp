/*! @file main.cpp
 * @brief Główny plik programu */

#include <string>
#include <iostream>
#include <cstdlib>

#include "tadrzewo.hh"

using namespace std;
 
int main ()
{
	TADrzewo<string, int> slownik;
	slownik["haha"] = 2;
	cout << slownik["haha"];

	return 0;
}
