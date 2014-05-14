/*!
 * \file macierz.cpp
 *
 *  Created on: 24 kwi 2014
 *      \author: szymon
 */

#include "macierz.hh"

template <typename Koszt_t>
Macierz<Koszt_t>::Macierz(unsigned n = 0)
{
	Tab.resize(n);
	for (unsigned i = 0; i < n; i++)
		(Tab[i]).resize(n, 0);
}

template <typename Koszt_t>
void Macierz<Koszt_t>::Powieksz(unsigned n)
{
	unsigned stary = Tab.size();

	Tab.resize(stary+n);
	for (unsigned i = 0; i < stary+n; i++)
		(Tab[i]).resize(stary+n, 0);
}

template <typename Koszt_t>
void Macierz <Koszt_t>::Usun(unsigned n)
{
	if (n >= Tab.size())
		return;

	Tab.erase(Tab.begin()+n);
	for (unsigned i = 0; i < Tab.size(); i++)
		(Tab[i]).erase((Tab[i]).begin() + n);
}

template <typename Koszt_t>
void Macierz<Koszt_t>::Wypisz (ostream & str)
{
	for (int i = 0; i < size(); i++) {
		for (int j = 0; j < size(); j++)
			str << (*this)(i, j) << '\t';

		str << '\n';
	}
}

template class Macierz<int>;
template class Macierz<double>;
