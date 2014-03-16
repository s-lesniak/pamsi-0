/*! @file main.cpp
 * @brief Główny plik programu */

#include <string>
#include <iostream>

#include "eksperyment.hh"

using namespace std;

/*!
 * \brief Nazwa pliku z wynikami badań */
const string wyjscie1 = "co1.csv";
const string wyjscie2 = "po2.csv";
 
int main ()
{
  try {
    if (JakiTryb() == CoJeden)
      Eksperyment glowny(wyjscie1, CoJeden);
    else
      Eksperyment glowny(wyjscie2, Podwajanie);
  }
  catch (exception &ex) {
    cerr << ex.what() << endl;
  }

  return 0;
}
