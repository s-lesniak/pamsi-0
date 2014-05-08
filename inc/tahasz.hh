/*!
 * \file tahasz.hh
 *
 *  Created on: 8 maj 2014
 *      Author: szymon
 */

#ifndef TAHASZ_HH_
#define TAHASZ_HH_

#include <vector>
#include <string>

#include "para.hh"

using namespace std;

/*!
 * \brief Tablica asocjacyjna zaimplementowana przez tablicę haszującą
 *
 * Szablon implementuje tablicę asocjacyjną z użyciem tablicy haszującej.
 * Konflikty w tablicy są rozwiązywanie z zastosowaniem próbkowania
 * liniowego. Poniższej tablicy haszującej nie da się powiększyć.
 *
 * Dla szczegółowego opisu działania tablicy asocjacyjnej i jej metod,
 * patrz szablon \ref TabAsoc (do którego niniejszy szablon jest
 * bliźniaczo podobny), o ile w opisie tego szablonu opisu brakuje.
 *
 * \tparam TypKlucza - musi istnieć dla niego funkcja haszująca Hasz(),
 * zapisana jako metoda tego szablonu
 */
template <typename TypKlucza, typename TypWartosci>
class TAHasz {

public:
	/*!
	 * Alokuje pamięć dla tablicy i ją tworzy.
	 *
	 * @param rozm - rozmiar tablicy (pozostanie niezmienny). Zaleca się,
	 * by był liczbą pierwszą.
	 */
	TAHasz (unsigned rozm);

	/*!
	 * Usuwa obiekt, zwalniając odpowiednio pamięć.
	 */
	~TAHasz ();

	bool Usun(const TypKlucza &k);

	TypWartosci& operator [] (const TypKlucza &k);

	unsigned IleElementow() const { return Zajetych; }

	/*!
	 * Informuje o ilości pamięci, jaka została zaalokowana tablicy.
	 * \return maksymalna ilość elementów, jaka jest w stanie się
	 * zmieścić w tablicy.
	 */
	unsigned IleMiejsca() const { return Rozmiar; }

	bool CzyPusta() const { return !IleElementow(); }

private:

	/*!
	 * Ilość elementów, jaka jest w stanie się zmieścić w tablicy.
	 */
	const unsigned Rozmiar;

	/*!
	 * Ilość rzeczywiście zajętych elementów tablicy.
	 */
	unsigned Zajetych;

	/*!
	 * \brief Właściwa tablica
	 *
	 * Każdy element jest wskaźnikiem na właściwą parę klucz-wartość,
	 * lub na NULL, jeżeli dane miejsce jeszcze nie jest zajęte.
	 */
	vector<*(Para<TypKlucza, TypWartosci>)> Tab;

	/*!
	 * \brief Funkcja haszująca
	 *
	 * Metoda zamienia zadany klucz w liczbę całkowitą z zakresu
	 * [0, Rozmiar-1] tak, by uzyskany wynik był indeksem, do którego
	 * zostanie wstawiony klucz.
	 * Metoda musi mieć osobne implementacje dla każdego typu danych,
	 * który będzie wykorzystywany jako \ref TypKlucza (z oczywistym
	 * wyjątkiem, gdy możliwa jest automatyczna konwersja).
	 *
	 * @param k - klucz, z którego ma zostać wyliczony hasz.
	 * \return liczba całkowita z zakresu [0, Rozmiar-1]
	 */
	unsigned Hasz(const TypKlucza &k);
};



#endif /* TAHASZ_HH_ */
