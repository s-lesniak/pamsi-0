/*! @file main.cpp
 * @brief Główny plik programu */

#include <string>
#include <iostream>
#include <cstdlib>

#include "tadrzewo.hh"

using namespace std;
 
int main ()
{
	Drzewo<int> drzewo;
	drzewo.Dodaj(4);
	drzewo.Dodaj(1);
	drzewo.Dodaj(54);
	cout << drzewo;

	drzewo.Usun(1);

	cout << drzewo;

	return 0;
}
