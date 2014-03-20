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

    *this = Zlacz(pierwsza, druga);
    return;
  }
  else return;
}

void TabLiczb::Podziel (TabLiczb &pierwsza, TabLiczb &druga)
{
  unsigned srodek = size() / 2;
  pierwsza.resize(srodek);
  druga.resize(size() - srodek);

  for (int i = 0; i < pierwsza.size(); i++)
    pierwsza[i] = at(i);

  for (int i = 0; i < druga.size(); i++)
    druga[i] = at(srodek + i);
}

TabLiczb& TabLiczb::Zlacz (const TabLiczb &pierwsza, 
			   const TabLiczb &druga)
{

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

