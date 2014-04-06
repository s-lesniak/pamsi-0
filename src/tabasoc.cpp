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
  cerr << "Funkcja Znajdz() - " << k << endl;
  if (!Rozmiar)
    throw out_of_range("nieee");

  int l = 0, p = Rozmiar - 1, sr;
  
  while (l <= p) {
    sr = (l+p) / 2;
    cerr << "l = " << l << ", p = " << p << ", sr = " << sr
	 << "\t" << Tab[PodIndeksem(sr)].Klucz << " =?= " << k << endl;
    if ((Tab[PodIndeksem(sr)]).Klucz == k)
      return sr;
    if ((Tab[PodIndeksem(sr)]).Klucz < k)
      l = sr + 1; 
    else
      p = sr - 1;
  }
  cerr << "l = " << l << ", p = " << p << endl;
  throw out_of_range("buu");
}

template <class TypKlucza, class TypWartosci>
TypWartosci& TabAsoc<TypKlucza, TypWartosci>::WstawKlucz
(const TypKlucza &k)
{
  cerr << "Funkcja WstawKlucz() - " << k << endl;
  Para<TypKlucza, TypWartosci> nowa(k);
  
  // znajdujemy iterator odpowiadający miejscu wstawienia nowego 
  // elementu
  list<unsigned>::iterator it = Indeks.begin();
  if (Rozmiar) {
    unsigned poz = ZnajdzMiejsce(k);
    for (unsigned i = 0; i < poz; i++)
      it++;
  }
  
  Indeks.insert(it, Rozmiar++);
  
  Tab.push_back(nowa);
  
  return Tab.back().Wart;
}

template <class TypKlucza, class TypWartosci>
unsigned TabAsoc<TypKlucza, TypWartosci>::ZnajdzMiejsce
(const TypKlucza &k) const
{
  cerr << "Funkcja ZnajdzMiejsce() - " << k << endl;
  int l = 0, p = Rozmiar, sr;
  
  while (l <= p) {
    sr = (l+p) / 2;
    cerr << "l = " << l << ", p = " << p << ", sr = " << sr
	 << "\t" << Tab[PodIndeksem(sr)].Klucz << " =?= " << k << endl;
          
    if ((Tab[PodIndeksem(sr)].Klucz) <= k) {
      if (sr+1 == Rozmiar)
	return sr+1; 
      else {
	if (k <= (Tab[PodIndeksem(sr+1)].Klucz))
	  return sr+1;
	else
	  l = sr+1;
      }
    }
    else
      p = sr-1;
  }
  cerr << "Tutaj nie powinniśmy byli dojść\n";
  return 0;
}

template <typename TypKlucza, typename TypWartosci>
unsigned TabAsoc<TypKlucza, TypWartosci>::PodIndeksem
(unsigned k) const
{
  list<unsigned>::const_iterator it = Indeks.begin();
  for (unsigned i = 0; i < k; i++)
    it++;

  return *it;
}

#include <string>

template class TabAsoc<string, double>;
