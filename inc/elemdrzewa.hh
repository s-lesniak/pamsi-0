/* \file elemdrzewa.hh
 * \brief Deklaracja szablonu struktury będącej elementem drzewa 
 * binarnego */

#ifndef ELEMDRZEWA_HH
#define ELEMDRZEWA_HH

#include <cstdlib>

/*!
 * \brief Pojedynczy element drzewa binarnego */
template <typename T> struct ElemDrzewa {

  ElemDrzewa(T start): elem(start), ldziecko(NULL), pdziecko(NULL) {}

  /*!
   * \brief Właściwa wartość elementu */
  T elem;

  /*!
   * \brief Wskaźniki do dzieci elementu */
  ElemDrzewa<T> *ldziecko;
  ElemDrzewa<T> *pdziecko;
};

#endif
