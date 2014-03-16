/*! @file koltab.cpp
 * @brief Definicje metod klasy KolTab */

#include <cstdlib>

#include "koltab.hh"

using namespace std;

void KolTab::push(int i)
{
  if (Ilosc + Roznica == Rozmiar) {
    int * nowa new int[Rozmiar? Rozmiar * 2 : 1];
    KopiujTab(Poczatek(), nowa, Ilosc);
    nowa[Ilosc] = i;

    delete[] Tablica;
    Tablica = nowa;

    Rozmiar = Rozmiar ? Rozmiar*2 : 1; Ilosc++; Roznica = 0;
  }
  else 
    Tablica[Roznica + Ilosc++] = i;
}

int KolTab::pop()
{
  int wartosc = Tablica[Roznica];

  if (Ilosc + Roznica < Rozmiar/4) {
    int * nowa = new int[Rozmiar/2];
    KopiujTab(Poczatek(), nowa, Ilosc - 1);
    Rozmiar /= 2;
  }
  Ilosc--; Roznica++;

  return wartosc;
}
