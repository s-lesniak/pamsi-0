/*! \file drzewo.cpp
 * \brief Definicje metod klasy Drzewo */

#include "elemdrzewa.hh"
#include "drzewo.hh"

using namespace std;

template <typename T>
T* Drzewo<T>::Dodaj (const T& elem)
{
	if (puste) {
		Korzen = elem;
		puste = false;
		return &(Korzen.elem);
	}

  ElemDrzewa<T> *nowy = new ElemDrzewa<T>;

  nowy->elem = elem;

  // szukamy miejsca dla nowego elementu

  ElemDrzewa<T> *i = new ElemDrzewa<T>;
  i = &Korzen;

  while(1)
  {
	  if (nowy->elem <= i->elem) {
		  if (nowy->elem == i->elem) {
			  return &(i->elem);
		  }
		  if (i->ldziecko)
			  i = i->ldziecko;
		  else {
			  i->ldziecko = nowy;
			  return &(i->ldziecko->elem);
		  }
	  }
	  else {
		  if (i->pdziecko)
			  i = i->pdziecko;
		  else {
			  i->pdziecko = nowy;
			  return &(i->pdziecko->elem);
		  }
	  }
  }
}

template <typename T>
void Drzewo<T>::Usun(const T& elem)
{


}

#include <string>

#include "para.hh"

template class Drzewo<int>;
template class Drzewo<Para<string, int> >;
template class Drzewo<Para<string, string> >;
