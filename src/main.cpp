/*! @file main.cpp
 * @brief Główny plik programu */

#include <string>
#include <iostream>

#include "tabasoc.hh"

using namespace std;
 
int main ()
{
  cout << "słowniczek polsko-niemiecki:\n";
  TabAsoc<string, string> slownik;
  slownik["telewizor"] = "Fernsehapparat";
  slownik["zabytek"] = "Sehenswürdigkeit";
  slownik["freon"] = "Fluorchlorkohlenwasserstoff";
  slownik["L4"] = "Arbeitsunfähigkeitsbescheinigung";

  slownik.WyswietlWPorzadku();

  cout << "\ntablica stałych matematycznych:\n";
  TabAsoc<string, double> stale;
  stale["e"] = 2.72;
  stale["sin(18°)"] = 0.309017;
  stale["pi"] = 3.14;

  stale.WyswietlWPorzadku();

  cout << "\n\nteraz conieco zmieniamy:\n";

  slownik["freon"] = "FCKW";
  slownik["L4"] = "Krankenschreibung";
  stale["e"] = 2.718281828459045;
  stale["pi"] = 3.1415926535897932384626;

  slownik.WyswietlWPorzadku();
  stale.WyswietlWPorzadku();
  return 0;
}
