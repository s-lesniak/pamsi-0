/*! \file drzewo.hh
 * \brief Deklaracja szablonu klasy implementującej drzewo binarne */
#ifndef DRZEWO_HH
#define DRZEWO_HH

#include <iostream>

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
   * dziecko jest mniejsze od ojca, a prawe - większe od
   * niego), a następnie wstawia tam jego kopię. Jeśli element do
   * wstawienia znajduje się już w drzewie, funkcja nie wstawia go
   * ponownie.
   *
   * \param[in] elem - element do wstawienia
   * \return wskaźnik na już wstawiony element */
  T* Dodaj(const T& elem);

  /*!
   * \brief Usuwa element z drzewa
   *
   * Wyszukuje zadany element, usuwa go z drzewa i przesuwa pozostałe
   * elementy tak, by struktura zachowywała charakter drzewa binarnego.
   *
   * @param elem - element do usunięcia
   */
  void Usun(const T& elem);

  /*! \brief Korzeń drzewa */
  ElemDrzewa<T> Korzen;

private:

  /*! \brief Flaga pustości drzewa
   *
   * Powinna być ustawiona na true, gdy drzewo jest puste, a na false,
   * gdy zawiera jakąś wartość.
   */
  bool puste;

  /*!
   * \brief Znajduje element drzewa
   *
   * Funkcja przeszukuje drzewo pod kątem zadanego wzorca i zwraca
   * wskaźnik na znaleziony element lub NULL.
   *
   * @param elem - wartość, której szukamy w drzewie
   * @return wskaźnik na znaleziony element
   * \retval NULL - elementu nie znaleziono
   */
  ElemDrzewa<T> Znajdz(const T& elem);
};

#endif
