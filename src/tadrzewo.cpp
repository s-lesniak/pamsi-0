/*! \file tadrzewo.cpp
 * \brief Definicje metod klasy TADrzewo */

#include <stdexcept>

#include "tadrzewo.hh"

template <typename TypKlucza, typename TypWartosci>
TypWartosci& TADrzewo<TypKlucza, TypWartosci>::operator []
(const TypKlucza &k)
{
	Para<TypKlucza, TypWartosci> *cel =
			Tab.Dodaj(Para<TypKlucza, TypWartosci> (k));

	Rozmiar++;

	return cel->Wart;
}

template <typename TypKlucza, typename TypWartosci>
bool TADrzewo<TypKlucza, TypWartosci>::Usun(const TypKlucza& k)
{
	if(Tab.Usun(Para<TypKlucza, TypWartosci> (k))) {
		Rozmiar--;
		return true;
	}
	else
		return false;
}

#include <string>

template class TADrzewo<string, int>;
template class TADrzewo<string, string>;
