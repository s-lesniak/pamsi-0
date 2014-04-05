/*! @file tabasoc.hh
 * @brief Deklaracja klasy implementującej tablicę asocjacyjną */

#ifndef TABASOC_HH
#define TABASOC_HH

#include <vector>
#include <list>

#include "para.hh"

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
 * zrealizowany operator >. Tym typem \b nie powinna być liczba
 * (zwłaszcza typu \verbatim int \endverbatim). Spowoduje to zaburzenia
 * przy odwoływaniu się do wartości poprzez ich indeks.
 * @tparam TypWartosci - typ danych, jakiego będą wartości. */
template <class TypKlucza, class TypWartosci>
class TabAsoc: public vector<Para<TypKlucza, TypWartosci> > {
public:

  /*!
   * @brief Zmienia wartość klucza lub dodaje klucz z wartością
   *
   * Funkcja sprawdza, czy zadany klucz znajduje się już w tablicy.
   * Jeżeli tak, przypisuje mu zadaną w parametrze wartość. W przeciwnym
   * wypadku tworzony jest nowy klucz wraz z przypisaną mu wartością.
   *
   * @param[in] k - modyfikowany/dodawany klucz
   * @param[in] v - przypisywana kluczowi wartość */
  void Zmien(const TypKlucza& k, const TypWartosci& v);

  /*!
   * @brief Usuwa z tablicy zadany klucz z odpowiadającą mu wartością.
   *
   * Z tablicy zostaje usunięty element zawierający podany klucz.
   * Przez wzgląd na konieczność realokacji dalszych elementow tablicy
   * funkcja ma stosunkowo kiepską złożoność obliczeniową (liniową w 
   * zależności od sumy ilości kasowanych i realokowanych elementów).
   * Odpowiednie wartości w Indeksie zostają zmniejszone o jeden.
   *
   * @retval true - dla znalezionego i usuniętego klucza
   * @retval false - w przypadku nieznalezienia klucza (funkcja wówczas
   * nie robi nic) */
  bool Usun(const TypKlucza& k);

  /*!
   * @brief Daje dostęp do wartości zadanego klucza
   *
   * Wyszukuje zadany w parametrze klucz i zwraca referencję do niego.
   * Jeżeli szukany klucz nie istnieje, jest on tworzony.
   *
   * @param[in] k - klucz odpowiadający żądanemu elementowi lub 
   * nowotworzony 
   * @return referencja do wartosci odpowiadającej kluczowi. */
  TypWartosci& Pobierz(TypKlucza k);

  /*!
   * @return Liczba elementów tablicy */
  unsigned IleElementow();

  /*!
   * @brief Sprawdza pustość tablicy 
   * @retval true - pusta tablica
   * @retval false - niepusta tablica */
  bool CzyPusta() { return !IleElementow(); }



private:

  /*!
   * @brief Informuje o kolejności danych w tablicy.
   *
   * Ze względu na ograniczenia związane z implementacją tablic C.D.N.*/
  list<unsigned> Indeks;
};

#endif
