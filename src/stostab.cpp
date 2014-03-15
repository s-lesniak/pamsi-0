/*! @file stostab.cpp
 * @brief Definicje metod klasy StosTab */

#include <cstdlib>
#include <iostream>

#include "stostab.hh"

StosTab::StosTab(TrybPracy tryb): Tablica(NULL), Rozmiar(0), Ilosc(0),
				  Tryb(tryb)
{
  if (Tryb)
    cout << "Tryb podwajania" << endl;
  else
    cout << "Tryb cojeden" << endl;
}

void StosTab::push(int i)
{
  if (Tryb == CoJeden)
    push_co1(i);
  else
    push_po2(i);

  return;
}

int StosTab::pop()
{
  if (Tryb == CoJeden)
    return pop_co1();
  // else
  return pop_po2();
}

void StosTab::push_co1 (int i)
{
  int * nowa = new int[Rozmiar + 1];
  KopiujTab(Tablica, nowa, Ilosc);
  nowa[Ilosc] = i;
  Rozmiar++; Ilosc++;

  delete[] Tablica;

  Tablica = nowa;
}

void StosTab::push_po2 (int i)
{
  if (Ilosc == Rozmiar) {
    int * nowa = new int[Rozmiar ? Rozmiar * 2 : 1];
    KopiujTab(Tablica, nowa, Ilosc);
    nowa[Ilosc] = i;

    delete[] Tablica;
    Tablica = nowa;

    Rozmiar = Rozmiar ? Rozmiar*2 : 1; Ilosc++;
  }
  else 
    Tablica[Ilosc++] = i;
}

int StosTab::pop_co1 ()
{
  int * nowa = new int[Rozmiar - 1];
  int wartosc = Tablica[Ilosc - 1];
  
  KopiujTab(Tablica, nowa, Ilosc - 1);
  Rozmiar--; Ilosc--;
  delete[] Tablica;
  Tablica = nowa;

  return wartosc;
}

int StosTab::pop_po2 ()
{
  int wartosc = Tablica[Ilosc - 1];

  if (Ilosc < Rozmiar/4) {
    int * nowa = new int[Rozmiar/2];
    KopiujTab(Tablica, nowa, Ilosc - 1);
    Rozmiar /= 2;
  }
  Ilosc--;

  return wartosc;
}

void KopiujTab (int* zrodlo, int* cel, unsigned n)
{
  for (unsigned i = 0; i < n; i++)
    cel[i] = zrodlo[i];
}
