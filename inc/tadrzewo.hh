/*! \file tadrzewo.hh
 * \brief Deklaracja klasy implementującej tablicę asocjacyjną przez 
 * drzewo binarne */

#ifndef TADRZEWO_HH
#define TADRZEWO_HH

#include <list>

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

};

#endif
