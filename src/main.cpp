/*! @file main.cpp
 * @brief Główny plik programu */

#include <string>
#include <iostream>

#include "eksperyment.hh"
#include "tabliczb.hh"

using namespace std;

/*!
 * \brief Nazwa pliku z wynikami badań */
const string wyjscie = "log.csv";
 
int main ()
{
  try {
    bool optym = Zapytaj();
    Eksperyment glowny(wyjscie, optym);
  }
  catch (exception &e) {
    cout << e.what() << endl;
  }

  return 0;
}
