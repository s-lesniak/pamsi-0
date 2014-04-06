/*! @file main.cpp
 * @brief Główny plik programu */

#include <string>
#include <iostream>

#include "tabasoc.hh"

using namespace std;
 
int main ()
{
  TabAsoc<string, double> jakas_tam;
  jakas_tam["lala"] = 2.4;
  jakas_tam["lili"] = 0.3;
  jakas_tam["mama"] = -9.2;

  return 0;
}
