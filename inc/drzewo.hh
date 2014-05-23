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
	Drzewo(): Korzen(NULL), puste(true) { }

  /*!
   * \brief Konstruuje jednoelementowe drzewo.
   *
   * \param[in] start - pierwszy element drzewa, który zostanie
   * postawiony na pozycji korzenia */
  Drzewo(T start): puste(false)
  { Korzen = new ElemDrzewa<T>; Korzen->elem = start; }

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
   * \retval true - element usunięto
   * \retval false - elementu nie usunięto, bo go nie znaleziono
   */
  bool Usun(const T& elem);

  /*!
   * \brief Znajduje element drzewa
   *
   * Funkcja przeszukuje drzewo pod kątem zadanego wzorca i zwraca
   * wskaźnik na ojca znalezionego elementu lub NULL.
   *
   * @param elem - wartość, której szukamy w drzewie
   * @return wskaźnik zadany elementu
   * \retval NULL - elementu nie znaleziono
   */
  ElemDrzewa<T>* Znajdz(const T& elem);

  /*! \brief Korzeń drzewa */
  ElemDrzewa<T>* Korzen;

private:

  /*! \brief Flaga pustości drzewa
   *
   * Powinna być ustawiona na true, gdy drzewo jest puste, a na false,
   * gdy zawiera jakąś wartość.
   */
  bool puste;

  /*!
   * \brief Znajduje następny w kolejności element drzewa
   *
   * Funkcja próbuje iść od zadanego węzła raz w prawo, a następnie
   * maksymalnie w lewo. Tak znaleziony węzeł będzie najmniejszym spośród
   * większych od węzła źródłowego.
   *
   * @param zr - węzeł drzewa, od którego funkcja rozpocznie poszukiwanie
   * @return wskaźnik na następny w kolejności węzeł
   * \retval NULL - nie istnieje prawe dziecko węzła \verbatim zr
   * \endverbatim .
   */
  ElemDrzewa<T>* Nast (ElemDrzewa<T>* zr);

  /*!
   * Wypisuje fragment drzewa na strumień, w porządku in-order.
   *
   * @param str - strumień na, który ma być wypisane fragment drzewa.
   * @param drz - wskaźnik na element, od którego funkcja ma rozpocząć
   * wypisywanie
   * @return referencja do strumienia wyjściowego
   */
  ostream& Wypisz (ostream & str, ElemDrzewa<T> *drz) const
  {
	  if (drz->ldziecko)
		  Wypisz(str, drz->ldziecko);
	  str << drz->elem << ' ';
	  if (drz->pdziecko)
		  Wypisz(str, drz->pdziecko);

	  return str;
  }

public:
  /*!
   * Wypisuje na strumień całe drzewo, w porządku in-order.
   * Wypis zostaje zwieńczony znakiem nowej linii.
   *
   * @param str - strumień wyjściowy
   * @param drz - drzewo do wypisania
   * @return referencja do strumienia wyjściowego
   */
  friend ostream& operator<< (ostream & str, const Drzewo<T>& drz)
  {
	  drz.Wypisz(str, drz.Korzen);
	  str << endl;
	  return str;
  }

};

#endif
