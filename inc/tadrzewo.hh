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
 * patrz szablon \ref TabAsoc (po którym niniejszy szablon dziedziczy). 
 */
template <typename TypKlucza, typename TypWartosci>
class TADrzewo: public TabAsoc {

public:
bool Usun(const TypKlucza& k);

TypWartosci& operator [] (const TypKlucza &k);

private:

  /*!
   * @brief Drzewo binarne implementujące właściwą tablicę */
  Drzewo<Para<TypKlucza, TypWartosci> > Tab;
  
  TypWartosci& WstawKlucz(const TypKlucza &k);

};

#endif
