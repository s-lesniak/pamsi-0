/*! @file tabliczb.cpp
 * @brief Definicje metod klasy TabLiczb */
#include <iostream>

#include "tabliczb.hh"

using namespace std;

bool TabLiczb::operator == (const TabLiczb& druga)
{
  unsigned roz = size();
  if (roz != druga.size())
    return false;

  for (unsigned i = 0; i < roz; i++) {
    if ((at(i) != druga.at(i)))
      return false;
  } 
  return true;
}

void TabLiczb::RazyDwa()
{
  for (unsigned i = 0; i < size(); i++) {
    this->at(i) *= 2;
  }
}

bool TabLiczb::ZamienElementy(unsigned i, unsigned j)
{
  if (i > size() || j > size()) {
    cerr << "Nieprawidłowy indeks przy zamienianiu elementów tablicy"
	 << endl;
    return false;
  }

  int tmp = at(i);

  at(i) = at(j);
  at(j) = tmp;

  return true;
}

void TabLiczb::OdwrocKolejnosc()
{
  OdwrocKolejnosc(0, size() - 1);
}

bool TabLiczb::OdwrocKolejnosc(unsigned i, unsigned j)
{
  if (i > size() || j > size () || i > j) {
    cerr << "Nieprawidłowy indeks przy odwracaniu tablicy";
    return false;
  }

  for (unsigned a = 0; a <= (i+j)/2 ; a++) {
    ZamienElementy(i+a, j-a);
  }
  return true;
}

void TabLiczb::MergeSort()
{
  if (size() > 1) {
    TabLiczb pierwsza, druga; // połówki sortowanej tablicy
  
    Podziel(pierwsza, druga);

    pierwsza.MergeSort();
    druga.MergeSort();

    *this = ZlaczSort(pierwsza, druga);
    
    return;
  }
  else {
    return;
  }
}

void TabLiczb::QuickSort()
{ QuickSort(0, size() - 1); }

void TabLiczb::HeapSort()
{
  //ZrobKopiec();

  unsigned koniec = size() - 1;

  while(koniec) {
  }
}

void TabLiczb::QuickSort(unsigned pocz, unsigned kon)
{
  unsigned i = pocz, j = kon;
  int x = (*this)[(i+j) / 2];
 
  do {
    while ((*this)[i] > x)
      i++;
    while ((*this)[j] < x)
      j--;
    if (i <= j) 
      Zamien(i++, j--);
  } while (i+1 <= j+1); /* powiększenie porównywanych liczb zapobiega
			   problemom z przepełnieniem zakresu */
  
  if (pocz+1 < j+1) // jw.
    QuickSort(pocz, j);
  if (i < kon)
    QuickSort(i, kon);
}

void TabLiczb::Podziel (TabLiczb &pierwsza, TabLiczb &druga)
{
  unsigned srodek = size() / 2;
  pierwsza.resize(srodek);
  druga.resize(size() - srodek);
  
  for (unsigned i = 0; i < pierwsza.size(); i++) 
    pierwsza[i] = at(i);

  for (unsigned i = 0; i < druga.size(); i++)
    druga[i] = at(srodek + i);
  
}

TabLiczb ZlaczSort (const TabLiczb &pierwsza, const TabLiczb &druga)
{
  TabLiczb wynik;

  wynik.resize(pierwsza.size() + druga.size());
  unsigned j = 0, k = 0; // do indeksowania tablic wejściowych

  for (unsigned i = 0; i < wynik.size(); i++) {
    
    if ((j < pierwsza.size()) && (pierwsza[j] > druga[k])) {
      wynik[i] = pierwsza[j++];
    }
    else
      wynik[i] = druga[k++];
    
  }
  return wynik;
}

TabLiczb& TabLiczb::operator + (const TabLiczb &zrodlo)
{ DodajElementy(*this, zrodlo); return *this; }

TabLiczb& TabLiczb::operator = (const TabLiczb& zrodlo)
{
  resize(zrodlo.size());

  for (unsigned i = 0; i < size(); i++) {
    at(i) = zrodlo[i];
  }
  return *this;
}

void DodajElementy (TabLiczb& zrodlo1, const TabLiczb& zrodlo2)
{
  for (unsigned i = 0; i < zrodlo2.size(); i++) {
    zrodlo1.push_back(zrodlo2[i]);
  }
}

ostream& operator << (ostream &str, const TabLiczb &tab)
{
  for (unsigned i = 0; i < tab.size(); i++)
    str << tab[i] << ' ';

  str << endl;

  return str;
}
