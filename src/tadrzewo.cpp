/*! \file tadrzewo.cpp
 * \brief Definicje metod klasy TADrzewo */

#include <stdexcept>

#include "tadrzewo.hh"

template <typename TypKlucza, typename TypWartosci>
TypWartosci& TADrzewo<TypKlucza, TypWartosci>::operator []
(const TypKlucza &k)
{
	if (!Rozmiar++) {
		Tab.Dodaj(Para<TypKlucza, TypWartosci> (k));
		return Tab.Korzen.elem.Wart;
	}

	ElemDrzewa<Para<TypKlucza, TypWartosci> > *i = &(Tab.Korzen);

	while (1) {
		if (k == (i->elem).Klucz) {
			Tab.Dodaj(Para<TypKlucza, TypWartosci> (k));
			return i->elem.Wart;
		}

		i = (k <= (i->elem).Klucz) ? i->ldziecko : i->pdziecko;
	}

	throw logic_error ("a");
}

#include <string>

template class TADrzewo<string, int>;
template class TADrzewo<string, string>;
