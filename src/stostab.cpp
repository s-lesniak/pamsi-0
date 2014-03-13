/*! @file stostab.cpp
 * @brief Definicje metod klasy StosTab */

#include <cstdlib>

#include "stostab.hh"

StosTab::StosTab(int i = 0): Tablica(NULL), Rozmiar(0), Ilosc(0)
{
  Tryb = i ? Podwajanie : CoJeden;
}

void StosTab::push(int i)
{
  if (Tryb == CoJeden)
    push_co1(int i);
  else
    push_po2(int i);

  return;
}

int StosTab::pop()
{
  if (Tryb == CoJeden)
    pop_co1(int i);
  else
    pop_po2(int i);

  return;
}

void StosTab::push_co1 (int i)
{
  int * nowa = new int[Rozmiar + 1];

  KopiujTab(Tablica, nowa, Rozmiar);
  nowa[Rozmiar] = i;

  delete[] Tablica;

  Tablica = nowa;
}

void StosTab::push_po2 (int i)
{

}

int StosTab::pop_co1 ()
{

}

int StosTab::pop_po2 ()
{

}
