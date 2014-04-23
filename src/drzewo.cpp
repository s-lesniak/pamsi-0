/*! \file drzewo.cpp
 * \brief Definicje metod klasy Drzewo */

#include "elemdrzewa.hh"
#include "drzewo.hh"

template <typename T>
void Drzewo<T>::Dodaj (const T& elem)
{
  ElemDrzewa<T> *nowy = new ElemDrzewa<T>;

  nowy->elem = elem;

  // szukamy miejsca dla nowego elementu

  ElemDrzewa<T> *i = new ElemDrzewa<T>;
  i = &Korzen;

  while(1)
	//  i = (*nowy <= *i) ? i->ldziecko : i->pdziecko;
  {
	  if (nowy->elem <= i->elem) {
		  if (i->ldziecko)
			  i = i->ldziecko;
		  else {
			  i->ldziecko = nowy;
			  break;
		  }
	  }
	  else {
		  if (i->pdziecko)
			  i = i->pdziecko;
		  else {
			  i->pdziecko = nowy;
			  break;
		  }
	  }
  }
}

template class Drzewo<int>;
