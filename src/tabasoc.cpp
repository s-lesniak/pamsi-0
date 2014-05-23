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
    return PodNumerem(PodIndeksem(gdzie));
  }
  catch (const out_of_range& ex) {\
    return WstawKlucz(k);
  }
}

template <class TypKlucza, class TypWartosci>
TypWartosci& TabAsoc<TypKlucza, TypWartosci>::PodNumerem (unsigned i)
{
  if (i >= Rozmiar())
    throw out_of_range ("bla");

  Para<TypKlucza, TypWartosci>& wynik = Tab[i];
  return wynik.Wart;
}

template <class TypKlucza, class TypWartosci>
unsigned TabAsoc<TypKlucza, TypWartosci>::Znajdz 
(const TypKlucza &k) const
{
  if (!Tab.size())
    throw out_of_range("nieee");

  int l = 0, p = Rozmiar() - 1, sr;
  
  while (l <= p) {
    sr = (l+p) / 2;
    
    if ((Tab[PodIndeksem(sr)]).Klucz == k)
      return sr;
    if ((Tab[PodIndeksem(sr)]).Klucz < k)
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
  if (Rozmiar()) {
    unsigned poz = ZnajdzMiejsce(k);
    for (unsigned i = 0; i < poz; i++)
      it++;
  }
  
  Indeks.insert(it, Rozmiar());
  
  Tab.push_back(nowa);
  
  return Tab.back().Wart;
}

template <class TypKlucza, class TypWartosci>
unsigned TabAsoc<TypKlucza, TypWartosci>::ZnajdzMiejsce
(const TypKlucza &k) const
{
  int l = 0, p = Rozmiar(), sr;
  
  while (l <= p) {
    sr = (l+p) / 2;
          
    if ((Tab[PodIndeksem(sr)].Klucz) <= k) {
      if (sr+1 == Rozmiar())
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

template <typename TypKlucza, typename TypWartosci>
void TabAsoc<TypKlucza, TypWartosci>::WyswietlWPorzadku
(ostream &str)
{
  str.width(25);
  str << left << "KLUCZ" << "WARTOŚĆ";
  for (int i = 0; i < Rozmiar(); i++) {
    str << '\n';
    str.width(25);
    str << left << Tab[PodIndeksem(i)].Klucz
	<< Tab[PodIndeksem(i)].Wart;
  }
  str << endl;
}

#include <string>

template class TabAsoc<string, double>;
template class TabAsoc<string, string>;
