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

  ~ElemDrzewa() { delete ldziecko, delete pdziecko; }

  /*! \brief Właściwa wartość elementu */
  T elem;

  /*!
   * \brief Wskaźniki do dzieci elementu */
  ElemDrzewa<T> *ldziecko;
  ElemDrzewa<T> *pdziecko;

  /*!
   * \brief Porównuje wartości przechowywane przez elementy */
  bool operator <= (const ElemDrzewa<T> &drugi)
  { return elem <= drugi.elem; }
};

#endif
