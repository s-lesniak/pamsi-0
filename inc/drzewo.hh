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
 * porównywać dwa egzemplarze swojego typu operatorem <=, wypisywać się
 * do strumienia (operatorem <<) i konwertować się do zera. */
template <typename T> class Drzewo {
public:

	/*!
	 * \brief Konstruuje puste drzewo
	 *
	 * Korzeń drzewa zostanie zinicjalizowany wartością zerową lub za pomocą
	 * domyślnego konstruktora klasy.
	 */
	Drzewo(): puste(true) { Korzen = T(); }

  /*!
   * \brief Konstruuje jednoelementowe drzewo.
   *
   * \param[in] start - pierwszy element drzewa, który zostanie
   * postawiony na pozycji korzenia */
  Drzewo(T start): Korzen(start), puste(false) {}

  /*!
   * \brief Wstawia element do drzewa.
   *
   * Zadanemu elementowi znajduje miejsce w drzewie (tak, że zawsze lewe
   * dziecko jest mniejsze/równe od ojca, a prawe - większe od 
   * niego), a następnie wstawia tam jego kopię.
   *
   * \param[in] elem - element do wstawienia */
  void Dodaj(const T& elem);

  /*! \brief Korzeń drzewa */
  ElemDrzewa<T> Korzen;


private:


  /*! \brief Flaga pustości drzewa
   *
   * Powinna być ustawiona na true, gdy drzewo jest puste, a na false,
   * gdy zawiera jakąś wartość.
   */
  bool puste;
};

#endif
