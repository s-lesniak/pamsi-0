/*! @file main.cpp
 * @brief Główny plik programu */

#include <string>
#include <iostream>
#include <cstdlib>

#include "tadrzewo.hh"

using namespace std;
 
int main ()
{
	srand(time(NULL));

	for (int i = 0; i < 20; i++) {
		Drzewo<int> drzewko;
		for (int i = 0; i < 10; i++)
			drzewko.Dodaj(rand()%4800);

		cout << drzewko.Korzen->elem << ' ';
		cout << (drzewko.Nast(drzewko.Korzen))->elem << endl;
	}
	return 0;
}
