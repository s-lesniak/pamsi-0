/*! @file main.cpp
 * @brief Główny plik programu */

#include <string>

#include "eksperyment.hh"

/*!
 * \brief Nazwa pliku z wynikami badań */
const std::string wyjscie = "log.csv";
 
int main ()
{
  Eksperyment glowny(wyjscie);

  return 0;
}
