/*! @file main.cpp
 * @brief Główny plik programu */

#include <string>
#include <iostream>

#include "tadrzewo.hh"
#include "drzewo.hh"

using namespace std;
 
int main ()
{
  Drzewo<int> przykl(8);

  przykl.Dodaj(2);

  cout << "korzeń: " << przykl.Korzen.elem << endl;
  // cout << "lewe dziecko: " << przykl.Korzen.pdziecko->elem << endl;
  return 0;
}
