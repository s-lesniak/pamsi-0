/*!
 * \file tahasz.cpp
 *
 *  Created on: 9 maj 2014
 *      Author: szymon
 */

#include <tahasz.hh>
//#include "para.hh"
//#include <cstdlib>
#include <stdexcept>
//#include <string>

using namespace std;

unsigned _FunHasz(const char* k, unsigned rozm)
{
	unsigned long long wynik = 1;
	unsigned i = 0;
	while (*k) {
		i++;
		wynik *= (int)(*k) * i;
		k++;
	}

	return _FunHasz(wynik, rozm);
}

template <typename TypKlucza, typename TypWartosci>
TAHasz<TypKlucza, TypWartosci>::TAHasz(unsigned rozm):
Rozmiar(rozm), Zajetych(0)
{
	Tab = new Para<TypKlucza, TypWartosci>* [rozm];
}

template <typename TypKlucza, typename TypWartosci>
TAHasz<TypKlucza, TypWartosci>::~TAHasz()
{
	for (int i = 0; i < Rozmiar; i++)
		delete Tab[i];

	delete [] Tab;
}

template <typename TypKlucza, typename TypWartosci>
TypWartosci& TAHasz<TypKlucza, TypWartosci>::operator [] (const TypKlucza &k)
{
	unsigned i = Hasz(k);

	while (Tab[i%Rozmiar]) {
		if (Tab[i%Rozmiar]->Klucz == k)
			return Tab[i%Rozmiar]->Wart;
		if (2*i > Rozmiar)
			throw out_of_range("pełna tablica");

		i++;
	}

	Tab[i%Rozmiar] = new Para<TypKlucza, TypWartosci>(k);
	Zajetych++;
	return Tab[i%Rozmiar]->Wart;
}

template <typename TypKlucza, typename TypWartosci>
bool TAHasz<TypKlucza, TypWartosci>::Usun (const TypKlucza &k)
{
	unsigned i = Hasz(k);

	while (Tab[i%Rozmiar] && 2*i <= Rozmiar) {
		if (Tab[i%Rozmiar]->Klucz == k) {
			delete Tab[i%Rozmiar];
			Tab[i%Rozmiar] = NULL;
			Zajetych--;
			return true;
		}
		i++;
	}

	return false;
}

template class TAHasz<string, int>;
template class TAHasz<int, double>;
