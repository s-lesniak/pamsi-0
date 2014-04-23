/*! @file main.cpp
 * @brief Główny plik programu */

#include <string>
#include <iostream>
#include <cstdlib>

#include "tadrzewo.hh"
#include "drzewo.hh"
#include "elemdrzewa.hh"

using namespace std;
 
int main ()
{
  Drzewo<int> A(0);

  for (int i = 0; i < 50; i++)
	  A.Dodaj(rand()%50);
  cout << "Elementy odczytywane idąc od góry, skręcając w lewą stronę: "
		  << endl;
  A.Korzen.Wypisz(cout);

  return 0;
}
