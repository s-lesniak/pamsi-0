/*! @file tabasoc.hh
 * @brief Deklaracja klasy implementującej tablicę asocjacyjną */

#ifndef TABASOC_HH
#define TABASOC_HH

using namespace std;

/*!
 * @brief Implementacja tablicy asocjacyjnej 
 *
 * Szablon implementuje tablicę asocjacyjną. Jest to spis niezmiennych
 * danych jednej klasy (nazywanej \b kluczem). Do każdego z kluczy 
 * przyporządkowany jest modyfikowalny element drugiej klasy (zwany \b
 * wartością).
 * Do wartości można się odwoływać zarówno poprzez numeryczny indeks
 * tablicy, jak i wartość klucza:
 *
 * \verbatim TabAsoc ludzie;
 * // ...
 * ludzie[9] -> "Johnny"
 * ludzie["Bravo"] -> "Johnny" \endverbatim
 *
 * @tparam TypKlucza - typ danych, jakiego będą klucze. Musi mieć
 * zrealizowany operator >
 * @tparam TypWartosci - typ danych, jakiego będą wartości*/
template <class TypKlucza, class TypWartosci>
class TabAsoc{
  
};

#endif
