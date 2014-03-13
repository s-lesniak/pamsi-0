/*! @file stostabl.hh
 * @brief Deklaracja klasy implementującej stos */

#ifndef STOSTAB_HH
#define STOSTAB_HH

#include <cstdlib>

using namespace std;

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
   * @brief Inicjalizacja pustego stosu */
  StosTab(): Tablica (NULL);

  /*!
   * @brief Kładzie liczbę na stos
   *
   * Zwiększa rozmiar tablicy o jeden, a na wolnym elemencie kładzie
   * nową liczbę 
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
  bool is_empty();

  /*!
   * @brief Zwraca ilość elementów na stosie */
  unsigned size();

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
};

#endif
