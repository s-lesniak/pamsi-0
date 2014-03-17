/*! @file kollist.cpp
 * @brief Metody klasy KolList */

#include <iostream>

#include "kollist.hh"

using namespace std;

void KolList::push(int i)
{
  if (!is_empty()) {
    ElemListy *kopia = Glowa;
    while(kopia->nast != NULL)
      kopia = kopia->nast;

    ElemListy *nowy = new ElemListy(i);
    kopia->nast = nowy;
  }
  else
    Glowa = new ElemListy(i);

  Ilosc++;
}

int KolList::pop()
{
  if (is_empty()) {
    cerr << "Pusta lista\n";
    return -1;
  }

  int wart = Glowa->wart;
  ElemListy *kopia = Glowa->nast;

  delete Glowa;
  Glowa = kopia;

  Ilosc--;

  return wart;
}
