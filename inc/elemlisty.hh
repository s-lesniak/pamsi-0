/*! @file elemlisty.hh
 * @brief Zawiera deklarację struktury tworzącej listy liczb int */

#ifndef ELEMLISTY_HH
#define ELEMLISTY_HH

#include <cstdlib>
/*!
 * @brief Struktura tworząca listę liczb typu int */
struct ElemListy {
  /*!
   * @brief Stworzenie elementu listy o zadanej treści
   * @param[in] i - liczba, którą chcemy jako element listy */
  ElemListy(int i): wart(i), nast(NULL) {}

  /*!
   * @brief Wartość przekazywana przez element */
  int wart;

  /*!
   * @brief Wskaźnik na następny element listy */
  ElemListy *nast;
};

#endif
