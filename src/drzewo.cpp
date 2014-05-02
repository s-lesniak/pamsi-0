/*! \file drzewo.cpp
 * \brief Definicje metod klasy Drzewo */

#include <cstdlib>
#include <stdexcept>

#include "elemdrzewa.hh"
#include "drzewo.hh"

using namespace std;

template <typename T>
T* Drzewo<T>::Dodaj (const T& elem)
{
	if (puste) {
		Korzen = new ElemDrzewa<T>;
		Korzen->elem = elem;
		puste = false;
		return &(Korzen->elem);
	}

  ElemDrzewa<T> *nowy = new ElemDrzewa<T>;

  nowy->elem = elem;

  // szukamy miejsca dla nowego elementu

  ElemDrzewa<T> *i = Korzen;

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
			  nowy->ojciec = i;
			  return &(i->ldziecko->elem);
		  }
	  }
	  else {
		  if (i->pdziecko)
			  i = i->pdziecko;
		  else {
			  i->pdziecko = nowy;
			  nowy->ojciec = i;
			  return &(i->pdziecko->elem);
		  }
	  }
  }
}

template <typename T>
void Drzewo<T>::Usun(const T& elem)
{
	ElemDrzewa<T> *cel = Znajdz(elem);
	ElemDrzewa<T> *nast = Nast(cel);
	//...
}

template <typename T>
ElemDrzewa<T>* Drzewo<T>::Znajdz (const T& elem)
{
	ElemDrzewa<T> *wzor = new ElemDrzewa<T>;
	ElemDrzewa<T> *i = Korzen;
	wzor->elem = elem;

	while(1)
	  {
		  if (wzor->elem <= i->elem) {
			  if (wzor->elem == i->elem) {
				  return i;
			  }
			  if (i->ldziecko) {
				  i = i->ldziecko;
			  }
			  else
				  return NULL;
		  }
		  else {
			  if (i->pdziecko) {
				  i = i->pdziecko;
			  }
			  else
				  return NULL;
		  }
	  }
}

template <typename T>
ElemDrzewa<T>* Drzewo<T>::Nast(ElemDrzewa<T> *zr)
{
	if(!(zr->pdziecko))
		return NULL;

	ElemDrzewa<T> *wynik = zr->pdziecko;
	while (wynik->ldziecko)
		wynik = wynik->ldziecko;

	return wynik;
}

#include <string>

#include "para.hh"

template class Drzewo<int>;
template class Drzewo<Para<string, int> >;
template class Drzewo<Para<string, string> >;
