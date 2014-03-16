/*! @file elemlisty.hh
 * @brief Zawiera deklarację struktury tworzącej listy liczb int */

#ifndef ELEMLISTY_HH
#define ELEMLISTY_HH

/*!
 * @brief Struktura tworząca listę liczb typu int */
struct ElemListy {
  /*!
   * @brief Wartość przekazywana przez element */
  int wart;

  /*!
   * @brief Wskaźnik na następny element listy */
  ElemListy *nast;
};

#endif
