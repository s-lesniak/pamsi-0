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
   * @brief Daje dostęp do wartości lub tworzy nowy klucz
   *
   * Sprawdza, czy w tablicy istnieje już klucz zadany w parametrze.
   * Jeśli tak, zwraca referencję do odpowiadającego mu klucza. W
   * przeciwnym wypadku tworzony jest nowy klucz (zapisanie w tablicy
   * oraz wstawienie odpowiedniego numeru do listy Indeks), a referencja
   * do nowoutworzonej wartości jest również zwracana.
   *
   * @warning Klucz zostanie stworzony także bez przypisania mu żadnej
   * wartości.
   * @param[in] k - klucz, który ma być znaleziony lub stworzony */
  TypWartosci& operator [] (const TypKlucza &k);

  /*!
   * @brief Daje dostęp do wartości według pozycji w tablicy
   *
   * W przypadku, gdy parametr jest mniejszy od wielkości tablicy,
   * funkcja zwraca referencję do wartości tablicy asocjacyjnej, która
   * odpowiada zadanej liczbie.
   * W przeciwnym wypadku rzuca wyjątek @verbatim end_of_range
   * @endverbatim.
   *
   * @param[in] i - liczony od zera indeks tablicy, z którego ma być
   * pobrana wartośc
   * @return referencja do zadanej wartości */
  TypWartosci& operator [] (unsigned i);

  /*!
   * @return Liczba elementów tablicy */
  unsigned IleElementow() const { return size(); }

  /*!
   * @brief Sprawdza pustość tablicy 
   * @retval true - pusta tablica
   * @retval false - niepusta tablica */
  bool CzyPusta() const { return !IleElementow(); }

private:

  /*!
   * @brief Informuje o kolejności danych w tablicy.
   *
   * Ze względu na ograniczenia związane z implementacją tablic istnieje
   * konieczność stworzenia struktury informującej, jak wygląda 
   * uporządkowana wersja tablicy. W tym celu stworzony został indeks,
   * w którym numery elementów tablicy są ułożone tak, by pozwalały na
   * proste odtworzenie posortowanej rosnąco tablicy.
   * Dla przykładu, gdy w poniższa lista zawierać będzie elementy:
   * @verbatim 4 0 1 3 2 @endverbatim , to piąty (czwarty, licząc od
   * zera) element tablicy jest pierwszy w kolejności, następnie 
   * pierwszy, drugi itd. */
  list<unsigned> Indeks;

  /*!
   * @brief Znajduje tablicowy numer elementu o zadanym kluczu.
   *
   * Funkcja dokonuje przeszukania binarnego tablicy (z pomocą listy
   * Indeks, która zawiera informacje o porządku elementów). Jeżeli
   * klucz nie zostanie odnaleziony, wyrzucony zostaje wyjątek @verbatim
   * out_of_range @endverbatim .
   *
   * @param[in] k - klucz, który ma zostać odnaleziony
   * @return numer, pod którym w tablicy znajduje się żądany klucz */
  unsigned Znajdz(const TypKlucza &k) const;

  /*!
   * @brief Tworzy nowy element tablicy
   *
   * Dodaje do tablicy parę z kluczem zadanym przez argument, oraz pustą
   * wartością. Informacja o nowym kluczu zostaje umieszczona w 
   * odpowiednim miejscu listy Indeks.
   *
   * @param[in] k - klucz, który ma zostać wstawiony
   * @return referencja do wartości odpowiadającej nowemu kluczowi */
  TypWartosci& WstawKlucz(const TypKlucza &k);
};

#endif
