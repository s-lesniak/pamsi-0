/*! @file tabasoc.cpp
 * @brief Definicje metod klasy TabAsoc */

#include <stdexcept>

#include "tabasoc.hh"

using namespace std;

TypWartosci& TabAsoc::operator [] (const TypKlucza &k)
{
  TypWartosci& wynik;

  throw {
    unsigned gdzie = Znajdz(k);
    wynik = gdzie.Wart;
  }
  catch (const out_of_range& ex) {
    wynik = WstawKlucz(k);
  }

  return wynik;
}

unsigned TabAsoc::Znajdz (const TypKlucza&) const
{

}

TypWartosci& WstawKlucz(const TypKlucza &k)
{

}
