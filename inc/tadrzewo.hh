/*! \file tadrzewo.hh
 * \brief Deklaracja klasy implementującej tablicę asocjacyjną przez 
 * drzewo binarne */

#ifndef TADRZEWO_HH
#define TADRZEWO_HH

#include <list>

#include "drzewo.hh"
#include "para.hh"
#include "tabasoc.hh"

using namespace std;

/*!
 * \brief Tablica asocjacyjna zaimplementowana poprzez drzewo binarne
 *
 * Szablon implementuje tablicę asocjacyjną z użyciem drzewa binarnego.
 * Dla szczegółowego opisu działania tablicy asocjacyjnej i jej metod,
 * patrz szablon \ref TabAsoc (do którego niniejszy szablon jest
 * bliźniaczo podobny).
 */
template <typename TypKlucza, typename TypWartosci>
class TADrzewo {

public:
	TADrzewo(): Rozmiar(0) { }

	bool Usun(const TypKlucza& k);

	TypWartosci& operator [] (const TypKlucza &k);

	  unsigned IleElementow() const { return Rozmiar; }

	  bool CzyPusta() const { return !IleElementow(); }

private:

  /*!
   * @brief Drzewo binarne implementujące właściwą tablicę */
  Drzewo<Para<TypKlucza, TypWartosci> > Tab;
  
  TypWartosci& WstawKlucz(const TypKlucza &k);

  unsigned Rozmiar;
};

#endif
