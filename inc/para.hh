/*! @file para.hh
 * @brief Deklaracja struktury implementującej parę elementów tablicy
 * asocjacyjnej */

#ifndef PARA_HH
#define PARA_HH

/*!
 * @brief Pojedynczy element tablicy asocjacyjnej
 *
 * Szablon struktury łączy dane dwóch typów, z czego pierwszy z nich 
 * jest stały (klucza i wartości). 
 *
 * @tparam TypKlucza - typ danych, jakiego będą klucze. Musi mieć
 * zrealizowany operatory <= i ==.
 * @tparam TypWartosci - typ danych, jakiego będą wartości. */
template <typename TypKlucza, typename TypWartosci>
struct Para {

  /*!
   * Konstruktor ustawiający klucz pary, wartość pozostaje nieokreślona
   */
  Para(const TypKlucza& k): Klucz(k) {}
 
  /*!
   * Stały element pary, według niego będzie posortowana tablica
   * asocjacyjna */
  TypKlucza Klucz;

  /*!
   * Zmienny element pary */
  TypWartosci Wart;
};

#endif
