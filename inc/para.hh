/*! @file para.hh
 * @brief Deklaracja struktury implementującej parę elementów tablicy
 * asocjacyjnej */

#ifndef PARA_HH
#define PARA_HH

#include <ostream>

using namespace std;

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
   * Konstruktor ustawiający klucz na zero lub wg konstruktora domyślnego
   */
  Para() { Klucz = TypKlucza(); }
 
  /*!
   * Stały element pary, według niego będzie posortowana tablica
   * asocjacyjna */
  TypKlucza Klucz;

  /*!
   * Zmienny element pary */
  TypWartosci Wart;

  /*!
   * Porównanie kluczów w dwóch parach.
   *
   * \param[in] druga - druga para do porównania.
   */
  bool operator <= (const Para<TypKlucza, TypWartosci> &druga)
		  { return Klucz <= druga.Klucz; }
  bool operator == (const Para<TypKlucza, TypWartosci> &druga)
		  { return Klucz == druga.Klucz; }

};

/*!
 * Wypisanie elementów pary na strumień. Najpierw klucz, potem wartość,
 * przedzielone tabulacjami.
 *
 * \param[in, out] str - strumień wyjściowy
 * \param[in] para - para, którą mamy wypisać
 */
template <typename TypKlucza, typename TypWartosci>
ostream& operator << (ostream& str,
		const Para<TypKlucza, TypWartosci> &para)
{
	str << para.Klucz << '\t' << para.Wart;
	return str;
}

#endif
