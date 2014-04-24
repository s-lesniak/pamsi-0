/*! \file tadrzewo.cpp
 * \brief Definicje metod klasy TADrzewo */

#include "tadrzewo.hh"

template <typename TypKlucza, typename TypWartosci>
TypWartosci& TADrzewo<TypKlucza, TypWartosci>::operator []
(const TypKlucza &k)
{
	if (!Rozmiar++) {
		Tab.Korzen = Para<TypKlucza, TypWartosci>(k);
		return Tab.Korzen.elem.Wart;
	}

	ElemDrzewa<Para<TypKlucza, TypWartosci> > *i = &(Tab.Korzen);


}

#include <string>

template class TADrzewo<string, int>;
template class TADrzewo<string, string>;
