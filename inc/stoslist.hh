/*! @file stoslist.hh
 * @brief Deklaracja klasy implementującej stos */

#ifndef STOSLIST_HH
#define STOSLIST_HH

#include <cstdlib>

#include "elemlisty.hh"

using namespace std;

/*!
 * @brief Stos liczb int zaimplementowany listą z głową */
class StosList {
public:
  
  /*!
   * @brief Inicjalizacja pustego stosu */
  StosList(): Glowa(NULL), Ilosc(0) {}

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
  bool is_empty() { return !Ilosc; }

  /*!
   * @brief Zwraca ilość elementów na stosie */
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
