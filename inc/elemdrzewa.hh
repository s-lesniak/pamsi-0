/* \file elemdrzewa.hh
 * \brief Deklaracja szablonu struktury będącej elementem drzewa 
 * binarnego */

#ifndef ELEMDRZEWA_HH
#define ELEMDRZEWA_HH

#include <cstdlib>
#include <iostream>

using namespace std;

/*!
 * \brief Pojedynczy element drzewa binarnego */
template <typename T> struct ElemDrzewa {

  ElemDrzewa(): elem((T) NULL), ldziecko(NULL), pdziecko(NULL) {}

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
  //bool operator <= (const ElemDrzewa<T> &drugi)
  //{ return elem <= drugi.elem; }

  /*!
   * \brief Przypisuje elementowi zadaną wartość
   */
  void operator = (const T wart)
  { elem = wart; }

  /*!
   * *\brief Wypisuje na zadany strumień fragment drzewa
   *
   * Na zadany strumień wypisuje element, z którego metoda jest wywoływana,
   * oraz wszystkie połączone z nią elementy w kolejności: najpierw korzeń
   * drzewa, następnie funkcja kolejne elementy na drodze do lewego skraju
   * drzewa, potem po jego obwodzie. Funkcja wywołuje siebie rekurencyjnie.
   *
   * \param[in] str - strumień, na który ma być wypisane drzewo
   */
  void Wypisz (ostream & str);
};

#endif
