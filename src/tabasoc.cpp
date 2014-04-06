/*! @file tabasoc.cpp
 * @brief Definicje metod klasy TabAsoc */

#include <stdexcept>
#include <iostream>

#include "tabasoc.hh"

using namespace std;

template <typename TypKlucza, typename TypWartosci>
TypWartosci& TabAsoc<TypKlucza, TypWartosci>::operator [] 
(const TypKlucza &k)
{
  try {
    unsigned gdzie = Znajdz(k);
    return PodNumerem(gdzie);
  }
  catch (const out_of_range& ex) {
    return WstawKlucz(k);
  }
}

template <class TypKlucza, class TypWartosci>
TypWartosci& TabAsoc<TypKlucza, TypWartosci>::PodNumerem (unsigned i)
{
  if (i >= Rozmiar)
    throw out_of_range ("bla");

  Para<TypKlucza, TypWartosci>& wynik = Tab[i];
  return wynik.Wart;
}

template <class TypKlucza, class TypWartosci>
unsigned TabAsoc<TypKlucza, TypWartosci>::Znajdz 
(const TypKlucza &k) const
{

  if (!Rozmiar)
    throw out_of_range("nieee");

  unsigned l = 0, p = Rozmiar, sr;
  
  while (l < p) {
    sr = (l+p) / 2;
    //cerr << l << ' ' << p << ' ' << sr << endl; 
    if ((Tab[sr]).Klucz == k)
      return sr;
    if ((Tab[sr]).Klucz < k)
      l = sr + 1;
    else
      p = sr - 1;
  }
  throw out_of_range("buu");
}

template <class TypKlucza, class TypWartosci>
TypWartosci& TabAsoc<TypKlucza, TypWartosci>::WstawKlucz
(const TypKlucza &k)
{
  Para<TypKlucza, TypWartosci> nowa(k);
  
  // znajdujemy iterator odpowiadający miejscu wstawienia nowego 
  // elementu
  list<unsigned>::iterator it = Indeks.begin();
  if (Rozmiar)
    for (unsigned i = 0; i < ZnajdzMiejsce(k); i++)
      it++;
  
  Indeks.insert(it, Rozmiar++);

  Tab.push_back(nowa);

  return Tab.back().Wart;
}

template <class TypKlucza, class TypWartosci>
unsigned TabAsoc<TypKlucza, TypWartosci>::ZnajdzMiejsce
(const TypKlucza &k) const
{
  unsigned l = 0, p = Rozmiar, sr;
  
  while (l <= p) {
    sr = (l+p) / 2;
    
    if ((Tab[sr].Klucz) <= k) {
      if (sr+1 == Rozmiar)
	return sr;
      else {
	if (k <= (Tab[sr+1].Klucz))
	  return sr+1;
	else
	  l = sr+1;
      }
    }
    else
      p = sr;
  }
  cerr << "Tutaj nie powinniśmy byli dojść\n";
  return 0;
}

#include <string>

template class TabAsoc<string, double>;
