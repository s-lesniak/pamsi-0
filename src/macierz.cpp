/*!
 * \file macierz.cpp
 *
 *  Created on: 24 kwi 2014
 *      \author: szymon
 */

#include "macierz.hh"

template <typename Koszt_t>
Macierz<Koszt_t>::Macierz(unsigned n)
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

template class Macierz<double>;
