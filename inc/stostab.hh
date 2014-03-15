/*! @file stostabl.hh
 * @brief Deklaracja klasy implementującej stos */

#ifndef STOSTAB_HH
#define STOSTAB_HH

using namespace std;

/*!
 * @brief Określa tryb pracy stosu */
enum TrybPracy {
  CoJeden = 0, /*! tablica stosu będzie się realokować przy każdej
		* zmianie */
  Podwajanie /*! tablica stosu będzie podwajać rozmiar przy 
	       * przekroczeniu rozmiaru, a zwalniać pamięć po osięgnięciu
	       * 1/4 */
};

/*!
 * @brief Stos zaimplementowany tablicą
 *
 * Stos może działać w dwóch trybach, różniących się tym, kiedy dochodzi
 * do zmiany struktury wewnętrznej stosu:
 * <li> realokacja tablicy o jeden przy każdym położeniu na stos i 
 * zdjęciu z niego </li>
 * <li> realokacja tablicy przy przekroczeniu jej wielkości, za każdym
 * razem zwiększając ją dwukrotnie. Zwolnienie pamięci zajdzie przy 
 * zajętości stosu poniżej 1/4. */
class StosTab {
public:

  /*!
   * @brief Inicjalizacja pustego stosu 
   *
   * @param[in] i - decyduje o trybie pracy stosu (p. opis klasy):
   * 0 dla wersji powiększającej o jeden
   * inna wartość dla wersji podwajającej
   * @warning Argument konstruktora NIE jest pierwszą liczbą na stosie!
   */
  StosTab(int i);

  /*!
   * @brief Kładzie liczbę na stos
   * @param[in] i - liczba do położenia na stosie */
  void push(int i);

  /*!
   * @brief Zdejmuje liczbę z wierzchu stosu
   * @return wartość zdjętego elementu */
  int pop();

  /*!
   * @brief Informuje użytkownika o zajętości stosu 
   * @retval true - dla pustego stosu (braku elementów)
   * @retval false - dla niepustego stosu */
  bool is_empty() { return !(Ilosc); }

  /*!
   * @brief Zwraca ilość elementów na stosie */
  unsigned size() { return Ilosc; }

private:
  /*!
   * @brief Wskaźnik na implementującą tablicę */
  int* Tablica;

  /*!
   * @brief Rozmiar stosu */
  unsigned Rozmiar;

  /*!
   * @brief Ilość elementów na stosie */
  unsigned Ilosc;

  /*!
   * @brief określa tryb pracy stosu */
  TrybPracy Tryb;

  /*!
   * @brief Kładzenie na stos w trybie CoJeden 
   * @param[in] i - liczba do położenia na stosie*/
  void push_co1(int i);

  /*!
   * @brief Kładzenie na stos w trybie Podwajanie
   * @param[in] i - liczba do położenia na stosie */
  void push_po2(int i);

  /*!
   * @brief Zdejmowanie ze stosu w trybie CoJeden
   * @return wartość zdjętego elementu */
  int pop_co1();

  /*!
   * @brief Zdejmowanie ze stosu w trybie Podwajanie
   * @return wartość zdjętego elementu */
  int pop_po2();

};

/*!
 * @brief Kopiowanie określonej ilości elementów tablicy
 *
 * Pewna ilość początkowych elementów jednej tablicy zostanie
 * przepisana do drugiej. Niezauważone zostanie przekroczenie zakresów
 * tablic.
 * @param[in] zrodlo - wskaźnik do tablicy, z której kopiowane zostaną
 * elementy
 * @param[out] cel - wskaźnik do tablicy, w której znajdą się 
 * skopiowane elementy. Musi mieć już konieczny dla kopiowania rozmiar.
 * @param[in] n - ilość elementów tablicy, jakie mają być skopiowane.
 * Jeżeli jest większe od rozmiaru tablicy, funkcja może dać 
 * nieprzewidziane wyniki */
void KopiujTab(int * zrodlo, int * cel, unsigned n);

#endif
