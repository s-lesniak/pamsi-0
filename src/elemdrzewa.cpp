/*
 * \file elemdrzewa.cpp
 *
 *  Created on: 23 kwi 2014
 *      Author: szymon
 */


#include "elemdrzewa.hh"

template <typename T>
void ElemDrzewa<T>::Wypisz(ostream & str)
{
	str << elem << endl;
	if (ldziecko)
		ldziecko->Wypisz(str);
	if (pdziecko)
		pdziecko->Wypisz(str);
}

template struct ElemDrzewa<int>;
