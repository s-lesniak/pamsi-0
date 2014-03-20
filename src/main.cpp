/*! @file main.cpp
 * @brief Główny plik programu */

#include <string>
#include <iostream>

#include "eksperyment.hh"

using namespace std;

/*!
 * \brief Nazwa pliku z wynikami badań */
const string wyjscie = "log.csv";
 
int main ()
{
  Eksperyment glowny(wyjscie);
 
  return 0;
}
