/*!
 * \file macierz.hh
 *
 *  Created on: 24 kwi 2014
 *      \author: szymon
 */

#ifndef MACIERZ_HH_
#define MACIERZ_HH_

#include <iostream>
#include <vector>

using namespace std;

/*!
 * \brief Tablica dwuwymiarowa.
 *
 * Struktura tworzy wygodny interfejs do operowania na dwuwymiarowych
 * tablicach typu liczbowego.
 *
 * \tparam Koszt_t liczbowy typ danych, którym będą wypełniane elementy
 * macierzy.
 */
template <typename Koszt_t>
class Macierz {
public:
	/*!
	 * \brief Stworzenie macierzy kwadratowej o zadanym wymiarze
	 *
	 * Konstruktor alokuje pamięć dla nowej macierzy, a wolne miejsca
	 * wypełnia zerami
	 *
	 * \param[in] n - rozmiar tworzonej macierzy
	 */
	Macierz(unsigned n);

	/*!
	 * \brief Daje dostęp do konkretnego elementu macierzy
	 *
	 * \warning Funkcja nie sprawdza poprawności indeksów.
	 * \param[in] i, j - indeksy elementu, do którego chcemy się dostać
	 * \return referencja do wartości pod zadanym indeksem
	 */
	Koszt_t& operator() (unsigned i, unsigned j)
	{ return Tab[i][j]; }
	Koszt_t operator() (unsigned i, unsigned j) const
	{ return Tab[i][j]; }
	/*!
	 * \brief Powiększa macierz kwadratową o określoną wielkość.
	 *
	 * Do macierzy zostaną dołączone w odpowiedniej ilości nowe wiersze
	 * i nowe kolumny. Nowe elementy są inicjalizowane zerami
	 *
	 * \param n - ilość wierszy/kolumn, o które ma być powiększona macierz
	 */
	void Powieksz (unsigned n);

	/*!
	 * \brief Pomniejsza macierz kwadratową o kolumnę i wiersz o zadanym
	 * indeksie
	 *
	 * Z macierzy zostają usunięte wszystkie elementy znajdujące się w
	 * zadanym wierszu lub kolumnie. Pozostałe zostają przesunięte tak,
	 * by cały czas tworzyć macierz kwadratową, o zmniejszonym już
	 * rozmiarze.
	 *
	 * \param[in] n - indeks kolumn/wierszy (liczony od zera), które
	 * chcemy wyciąć. Jeżeli jest spoza granic macierzy, funkcja nie
	 * będzie robić nic.
	 */
	void Usun (unsigned n);

	/*! Podaje obecny rozmiar macierzy	 */
	size_t size() { return Tab.size(); }

	/*!
	 * \brief Wypisanie na strumień zadanej macierzy.
	 *
	 * Każdy z wierszy macierzy będzie wypisany w osobnej linii, a w
	 * zakresie jednej linii poszczególne liczby zostaną oddzielone znakami
	 * tabulacji, np.:
	 * \code
	 * 0	9	15
	 * 14	6	1
	 * 9	3	27
	 * \endcode
	 *
	 * \tparam Koszt_t - typ danych, którym jest wypełniona macierz. Musi
	 * dać się wypisać na strumień, najlepiej tak, by mieścił się w jednej
	 * linii.
	 * @param str - strumień wyjściowy do wypisania macierzy
	 */
	void Wypisz(ostream & str);

private:
	/*!
	 * \brief Właściwa tablica przechowująca wartości
	 */
	vector<vector<Koszt_t> > Tab;
};


#endif /* MACIERZ_HH_ */
