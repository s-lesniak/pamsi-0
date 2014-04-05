/*! @file tabasoc.cpp
 * @brief Definicje metod klasy TabAsoc */

#include <stdexcept>
#include <iostream>

#include "tabasoc.hh"

using namespace std;

template <class TypKlucza, class TypWartosci>
TypWartosci& TabAsoc<TypKlucza, TypWartosci>::operator [] 
(const TypKlucza &k)
{
  TypWartosci& wynik;

  try {
    unsigned gdzie = Znajdz(k);
    wynik = (*this)[gdzie].Wart;
  }
  catch (const out_of_range& ex) {
    wynik = WstawKlucz(k);
  }

  return wynik;
}

template <class TypKlucza, class TypWartosci>
unsigned TabAsoc<TypKlucza, TypWartosci>::Znajdz 
(const TypKlucza&) const
{

}

template <class TypKlucza, class TypWartosci>
TypWartosci& TabAsoc<TypKlucza, TypWartosci>::WstawKlucz
(const TypKlucza &k)
{
  Para<TypKlucza, TypWartosci> nowa(k);
  
  Indeks.insert(Indeks.begin() + ZnajdzMiejsce(k), Rozmiar++);

  push_back(nowa);

  return nowa.Wartosc;
}

template <class TypKlucza, class TypWartosci>
unsigned TabAsoc<TypKlucza, TypWartosci>::ZnajdzMiejsce
(const TypKlucza &k) const
{
  unsigned l = 0, p = Rozmiar, sr;
  list<unsigned>::iterator it;

  while (l <= p) {
    sr = (l+p) / 2;
    if ((*this)[sr] <= k) {
      if (k <= (*this)[sr+1])
	return sr+1;
      else
	l = sr+1;
    }
    else
      p = sr;
  }
  cerr << "Tutaj nie powinniśmy dojść\n";
  return 0;
}
