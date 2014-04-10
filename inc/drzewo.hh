/*! \file drzewo.hh
 * \brief Deklaracja szablonu klasy implementującej drzewo binarne */
#ifndef DRZEWO_HH
#define DRZEWO_HH

#include <cstdlib>

#include "elemdrzewa.hh"

using namespace std;

/*!
 * \brief Implementacja drzewa binarnego
 *
 * Szablon implementuje drzewo binarne zadanego przez użytkownika typu.
 * Jest obudowany typowym dla drzew interfejsem.
 *
 * \tparam T - typ danych, jakie ma przechowywać drzewo. Musi umieć
 * porównywać dwa egzemplarze swojego typu operatorem <=. */
template <typename T> class Drzewo {
public:

  /*!
   * \brief Konstruuje jednoelementowe drzewo.
   *
   * \param[in] start - pierwszy element drzewa, który zostanie
   * postawiony na pozycji korzenia */
  Drzewo(T start): Korzen(start) {}

  /*!
   * \brief Wstawia element do drzewa.
   *
   * Zadanemu elementowi znajduje miejsce w drzewie (tak, że zawsze lewe
   * dziecko jest mniejsze/równe od ojca, a prawe - większe od 
   * niego), a następnie wstawia tam jego kopię.
   *
   * \param[in] elem - element do wstawienia */
  void Dodaj(const T& elem);

  //private:

  /*! \brief Korzeń drzewa */
  ElemDrzewa<T> Korzen;
};

#endif
