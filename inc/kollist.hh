/*! @file kollist.hh
 * @brief Deklaracja klasy implementującej kolejkę */

#ifndef KOLLIST_HH
#define KOLLIST_HH

#include <cstdlib>

#include "elemlisty.hh"

using namespace std;

/*!
 * @brief Kolejka liczb int zaimplementowany listą z głową */
class KolList {
public:
  
  /*!
   * @brief Inicjalizacja pustej kolejki */
  KolList(): Glowa(NULL), Ilosc(0) {}

  /*!
   * @brief Kładzie liczbę do kolejki
   * @param[in] i - liczba do położenia w kolejce */
  void push(int i);

  /*!
   * @brief Zdejmuje liczbę z początku kolejki
   * @return wartość zdjętego elementu */
  int pop();

  /*!
   * @brief Informuje użytkownika o zajętości kolejki
   * @retval true - dla pustej kolejki (braku elementów)
   * @retval false - dla niepustej kolejki */
  bool is_empty() { return !Ilosc; }

  /*!
   * @brief Zwraca ilość elementów w kolejce */
  unsigned size() { return Ilosc; }

private:
  /*!
   * @brief Początek listy
   *
   * Wskaźnik na pierwszy element stosu */
  ElemListy* Glowa;

  /*!
   * @brief Ilość elementów na stosie */
  unsigned Ilosc;
};

#endif
