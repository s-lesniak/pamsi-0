/* \file elemdrzewa.hh
 * \brief Deklaracja szablonu struktury będącej elementem drzewa 
 * binarnego */

#ifndef ELEMDRZEWA_HH
#define ELEMDRZEWA_HH

/*!
 * \brief Pojedynczy element drzewa binarnego */
template <typename T> struct ElemDrzewa {

  /*!
   * \brief Właściwa wartość elementu */
  T elem;

  /*!
   * \brief Wskaźniki do dzieci elementu */
  ElemDrzewa<T> *ldziecko;
  ElemDrzewa<T> *pdziecko;
};

#endif
