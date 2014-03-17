/*! @file stoslist.cpp
 * @brief Metody klasy StosList */

#include <iostream>

#include "stoslist.hh"

void StosList::push(int i)
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

int StosList::pop()
{
  if (is_empty()) {
    cerr << "Pusta lista\n";
    return -1;
  }

  int wart;
  ElemListy *kopia = Glowa;
  for (unsigned i = 0; i+1 < Ilosc; i++)
    kopia = kopia->nast;

  wart = kopia->wart;
  Ilosc--;

  return wart;
}
