/*!
 * \file graf.hh
 *
 *  Created on: 24 kwi 2014
 *      \author: szymon
 */

#ifndef GRAF_HH_
#define GRAF_HH_

#include <vector>
#include <list>

#include "macierz.hh"
#include "punkt.hh"

using namespace std;

/*!
 * \brief Modeluje graf nieskierowany
 *
 * Szablon implementuje pojęcie grafu nieskierowanego. Możliwy jest wybór
 * typów danych, jakimi będą węzeł i koszt krawędzi w grafie.
 * Wewnątrz, do opisania struktury grafu wykorzystywana jest tablica węzłów
 * oraz macierz sąsiedztwa.
 * Węzły w grafie muszą być unikatowe.
 *
 * \tparam Wezel_t typ danych, jaki będzie wykorzystywany do opisania węzła.
 * Musi się wypisywać na strumień operatorem << i porównywać operatorem <.
 * \tparam Koszt_t liczbowy typ danych, który będzie opisywał koszt (wagę)
 * krawędzi w grafie. Dla opisanie grafu bez wag można obrać \verbatim
 * bool \endverbatim za ten typ.
 */
template <typename Wezel_t, typename Koszt_t>
class Graf {
public:

	/*!
	 * Tworzy graf bez żadnych wierzchołków
	 */
<<<<<<< HEAD
	Graf(): Wezly(), MSas(0), Indeks() { }
=======
	Graf(): Wezly(), MSas(0), Indeks() { licznik = 0; }
>>>>>>> origin/master

	/*!
	 * Tworzy graf z jednym wierzchołkiem startowym.
	 * @param pierw_wezel - pierwszy stworzony wierzchołek grafu.
	 */
	Graf(const Wezel_t & pierw_wezel): Wezly(1, pierw_wezel), MSas(1),
			Indeks(1, 0) {}

	/*!
	 * \brief Wstawia węzeł
	 *
	 * Sprawdza, czy element już istnieje w grafie. Jeśli nie, wstawia
	 * go odpowiednio do \ref Wezly i znajduje odpowiedni \ref Indeks.
	 * Wstawiony węzeł nie będzie połączony z żadnym innym.
	 *
	 * @param elem - węzeł do wstawienia
	 * @retval true - elementu dotychczas nie było i udało się go
	 * wstawić
	 * \retval false - element znajdował się już w grafie
	 */
	bool Dodaj(const Wezel_t & elem);

	/*!
	 * \brief Wstawia lub zmienia krawędź między dwa węzły
	 *
	 * Szuka w grafie zadane elementy. Jeżeli zostaną znalezione, to
	 * tym węzłom zostanie przypisany zadany koszt. Funkcja nie
	 * sprawdza, czy połączenie dotychczas już istniało.
	 * Jako że klasa reprezentuje graf nieskierowany, kolejność podanych
	 * elementów nie gra roli.
	 *
	 * @param elem1 - pierwszy element do połączenia
	 * @param elem2 - drugi element do połączenia
	 * @param koszt - koszt, jaki ma być nadany połączeniu. Ustawienie
	 * wartości 0 jest równoznaczne z usunięciem krawędzi.
	 * @retval true - oba elementy zostały znalezione, a krawędź dodana
	 * lub zmodyfikowana
	 * \retval false - jeden z elementów nie został znaleziony
	 */
	bool Dodaj(const Wezel_t & elem1, const Wezel_t & elem2,
			const Koszt_t & koszt);

	/*!
	 * \brief Usuwa węzeł
	 *
	 * Wraz z węzłem zostaną usunięte wszystkie krawędzie, które się
	 * do niego odnosiły.
	 * @param elem - węzeł do usunięcia
	 * @retval true - element znaleziony i usunięty
	 * \retval false - element nieznaleziony
	 */
	bool Usun(const Wezel_t & elem);

	/*!
	 * \brief Usuwa krawędź
	 *
	 * Funkcja równoważna edycji krawędzi (funkcja \ref Dodaj) przy
	 * koszt = 0.
	 *
	 * @param elem1 - pierwszy element do połączenia
	 * @param elem2 - drugi element do połączenia
	 * @retval true - oba elementy zostały znalezione, a krawędź dodana
	 * lub zmodyfikowana
	 * \retval false - jeden z elementów nie został znaleziony
	 */
	bool UsunKr(const Wezel_t & elem1, const Wezel_t & elem2)
	{ return Dodaj(elem1, elem2, 0); }

	/*!
	 * \brief Pokazuje odległość bezpośrednieego połączenia
	 *
	 * @param elem1 - pierwszy element do połączenia
	 * @param elem2 - drugi element do połączenia
	 * @return Odległość pomiędzy zadanymi elementami (0 dla elementów
	 * niepołączonych)
	 */
	Koszt_t Odleglosc(const Wezel_t & elem1, const Wezel_t & elem2) const
	{ return MSas(Znajdz(elem1), Znajdz(elem2)); }

	/*!
	 * \brief Pokazuje odległość bezpośrednieego połączenia
	 *
	 * @param elem1 - nr pierwszego elementu do połączenia
	 * @param elem2 - nr drugiego elementu do połączenia
	 * @return Odległość pomiędzy zadanymi elementami (0 dla elementów
	 * niepołączonych)
	 */
	Koszt_t Odleglosc(unsigned elem1, unsigned elem2) const
	{ return MSas(elem1, elem2); }

	/*!
	 * \brief Szuka bezpośrednich sąsiadów danego węzła
	 *
	 * Funkcja szuka, czy istnieje połączenie między węzłem zadanym a
	 * każdym pozostałych z osobna. Wartości węzłów, z którymi jest
	 * połączenie, zapisuje do nowoutworzonego wektora.
	 *
	 * @param elem - element, którego sąsiadów chcemy poznać
	 * @return Wektor z wypisanymi sąsiadami zadanego elementu.
	 * Wypisanie nastąpi zgodnie z kolejnością w tablicy węzłów.
	 */
	vector<Wezel_t> Sasiedztwo(const Wezel_t & elem) const;

	/*!
	 * \brief Przechodzi graf wszerz
	 *
	 * Implementacja algorytmu przechodzenia wszerz (breadth-first
	 * search, stąd nazwa funkcji). Zaczynając od pewnego wierzchołka,
	 * zapisane zostaną kolejni sąsiedzi. Po skończeniu jednego
	 * "poziomu", algorytm rozpoczyna szukanie sąsiadów wśród przed
	 * chwilą wypisanych węzłów.
	 *
	 * @param start - nr wierzchołka, od którego rozpoczniemy
	 * przechodzenie
	 * \param koniec - nr wierzchołka, do którego chcemy dojść
	 * @return wektor węzłów uporządkowanych w kolejności przejścia BFS
	 */
	vector<unsigned> BFS(unsigned start, unsigned koniec) const;

	vector<unsigned> BFS(const Wezel_t & start, const Wezel_t & koniec) const
		{ return BFS(Znajdz(start), Znajdz(koniec)); }

	/*!
	 * \brief Przechodzi graf wgłąb
	 *
	 * Implementacja algorytmu przechodzenia wgłąb (depth-first search,
	 * stąd nazwa funkcji). Zaczynając od pewnego wierzchołka,
	 * zapisywany jest pewien jego sąsiad. Procedura jest powtarzana aż
	 * do dotarcia do węzła bez nowych (niezapisanych dotychczas)
	 * sąsiadów. Następnie funkcja wraca do wierzchołka wyżej.
	 *
	 * @param start - nr wierzchołka, od którego rozpoczniemy
	 * przechodzenie
	 * \param koniec - nr wierzchołka, do którego chcemy dojść
	 * @return wektor węzłów uporządkowanych w kolejności przejścia DFS
	 */
	vector<unsigned> DFS(unsigned start, unsigned koniec) const;

	vector<unsigned> DFS(const Wezel_t & start, const Wezel_t & koniec) const
		{ return DFS(Znajdz(start), Znajdz(koniec)); }

	/*!
	 * \brief Przejście grafu alogrytmem A*
	 *
	 * Implementacja efektywnego algorytmu wyszukiwania najkrótszej ścieżki
	 * w grafie. Oparty jest na istnieniu heurystyki (dodatkowej funkcji
	 * szacującej) odległości między dowolnymi elementami grafu. Jest to
	 * powód, dla którego algorytm jest zdefiniowany tylko dla węzłów tylko
	 * jednego typu danych.
	 *
	 * @param start - nr wierzchołka, od którego rozpoczniemy
	 * przechodzenie
	 * \param koniec - nr wierzchołka, do którego chcemy dojść
	 * @return wektor węzłów uporządkowanych w kolejności przejścia A*
	 */
	vector<unsigned> AStar(unsigned start, unsigned koniec) const;

	vector <unsigned> AStar(const Wezel_t &start, const Wezel_t &koniec) const
		{ return AStar(Znajdz(start), Znajdz(koniec)); }

	/*!
	 * \brief Aproksymuje rozwiązanie problemu komiwojażera
	 *
	 * Funkcja przechodzi wszystkie elementy grafu pełnego z wykorzystaniem
	 * algorytmu najbliższego sąsiada (ang. Nearest Neighbor), tzn. każdorazowo
	 * szuka najbliższego nieodwiedzonego dotychczas węzła.
	 *
	 * @param start - nr wierzchołka, od którego rozpoczęte zostanie przejście
	 * @return wektor węzłów uporządkowanych w kolejności ww. przejścia
	 */
	vector<unsigned> TSP_NN(unsigned start) const;

	vector<unsigned> TSP_NN(const Wezel_t &start) const
		{ return TSP_NN(Znajdz(start)); }

	/*!
	 * \brief Daje "antyrozwiązanie" problemu komiwojażera
	 *
	 * Funkcja każdokrotnie szuka losowy z dotychczas niezwiedzonych wierzchołków.
	 * Jest zamierzona jako przykład skrajnie nieefektywnego rozwiązaniu TSP, i
	 * przeznaczona do wielokrotnego wywołania i uśrednienia wyników.
	 * @param start - nr wierzchołka, od którego rozpoczęte zostanie przejście
	 * @return wektor węzłów uporządkowanych w kolejności ww. przejścia
	 */
	vector<unsigned> TSP_rand(unsigned start) const;

	vector<unsigned> TSP_rand(const Wezel_t &start) const
		{ return TSP_rand(Znajdz(start)); }

	/*!
	 * Konwertuje wektor z indeksami wierzchołków grafu na wektor z ich
	 * wartościami
	 */
	vector<Wezel_t> ZnajdzWartosci(const vector<unsigned>& zr) const;

	/*!
	 * \brief Szuka indeksu zadanego elementu
	 *
	 * Funkcja szuka zadanego parametrem węzła w grafie. Jeżeli go nie
	 * znajdzie, rzuca wyjątek, w przeciwnym razie podaje odpowiadający
	 * węzłowi numer kolumny/wiersza w macierzy sąsiedztwa.
	 *
	 * @param elem - element do znalezienia
	 * \return indeks znalezionego elementu (w wektorze węzłów lub macierzy
	 * sąsiedztwa)
	 */
	unsigned Znajdz(const Wezel_t& elem) const;

	/*!
	 * \brief Wczytuje wierzchołki z pliku CSV
	 *
	 * Funkcja pobiera od użytkownika nazwę pliku z wierzchołkami grafu.
	 * Powinien zachowywać strukturę CSV, gdzie kolejne kolumny będą oznaczać:
	 * nazwę wierzchołka, szerokość i długość geograficzną.
	 * Dla przypomnienia: szerokość może być północa lub południowa (zakres
	 * [-90; 90], a  długość - zachodnia lub wschodnia ([-180; 180]).
	 */
	void WczytajWierzcholki();

	/*!
	 * \brief Wczytuje informacje o krawędziach grafu
	 *
	 * Funkcja pobiera od użytkownika nazwę pliku z krawędziami grafu.
	 * Powinien zachowywać strukturę CSV, gdzie kolejne kolumny to: nazwy
	 * dwóch łączonych wierzchołków, koszt połączenia między nimi.
	 */
	void WczytajKrawedzie();

	/*!
	 * \brief Liczy łączny koszt przejścia w grafie
	 *
	 * Funkcja bierze wektor opisujący ścieżkę w grafie i sumuje wartości
	 * krawędzi odpowiadającym jego elementom.
	 *
	 * @param sciezka - wektor opisujący ścieżkę, którą chcemy zliczać
	 * @return Łączny koszt przejścia po zadanej ścieżce.
	 * \retval -1.0 - Zadany wektor nie podaje ścieżki przejścia (istnieją
	 * elementy niepołączone bezpośrednio)
	 */
	Koszt_t LacznyKoszt(const vector<unsigned>& sciezka);

	long int Licznik() { return licznik; }

	/*!
	 * \brief Struktura wewnętrzna przejścia A*
	 *
	 * Celem zaspokojenia wymagań algorytmu A*, oprócz samego numeru węzła
	 * pojawia się tu także koszt przejścia do zadanego węzła, licząc od
	 * wybranego punktu startowego.
	 */
	struct AStar_elem {
		/*! Numer węzła */
		unsigned nr;

		/*! Koszt przejścia z węzła startowego w przejściu A* */
		Koszt_t koszt;

		AStar_elem(unsigned nr = 0, Koszt_t koszt = 0): nr(nr), koszt(koszt)
		{ }

		bool operator < (const AStar_elem& dr) const
		{ return nr < dr.nr; }
	};

	/*!
	 * \brief Wypisuje na stumień znalezioną ścieżkę
	 *
	 * Na żądanym strumieniu zostaną wypisane nazwy punktów (znalezione z
	 * pomocą odpowiadających im numerów w tablicy \ref Wezly). Pomiędzy
	 * nimi wypisana zostanie odległość między węzłami, zgodnie ze schematem:
	 * A --(15 km)--> B --(82.1 km)--> C
	 *
	 * @param sciezka wektor opisujący ścieżkę, którą chcemy wypisać
	 * @param str - strumień, na którym mają się znaleźć informacje.
	 */
	void PokazTrase(const vector<unsigned>& sciezka, ostream& str = cout);

private:

	/*!
	 * \brief Tablica węzłów istniejących w grafie
	 *
	 * Tablica zawiera węzły w kolejności, w jakiej są wstawiane do
	 * grafu. Oprócz tego wektora, potrzebny jest także element \ref
	 * Indeks, który informuje o kolejności elementów.
	 */
	vector<Wezel_t> Wezly;

	/*!
	 * \brief Macierz sąsiedztwa grafu
	 *
	 * Ułożona jest w taki sposób, by n-temu elementowi wektora \ref
	 * Wezly odpowiadał n-ty wiersz i rząd niniejszej macierzy.
	 * Elementy macierzy są wagami odpowiednich krawędzi grafu. Zero
	 * oznacza brak połączenia między nimi.
	 */
	Macierz<Koszt_t> MSas;

	/*!
	 * \brief Lista kontrolująca kolejność węzłów
	 *
	 * W celu umożliwienia binarnego przeszukiwania węzłów, konieczna jest
	 * struktura informująca, jak wygląda uporządkowana wersja tablicy.
	 * W tym celu stworzony został indeks, w którym numery elementów
	 * tablicy są ułożone tak, by pozwalały na proste odtworzenie
	 * posortowanej rosnąco tablicy.
	 *
	 * Dla przykładu, gdy w poniższa lista zawierać będzie elementy:
	 * @verbatim 4 0 1 3 2 @endverbatim , to piąty (czwarty, licząc od
	 * zera) element tablicy jest pierwszy w kolejności, następnie
	 * pierwszy, drugi itd.
	 */
	list <unsigned> Indeks;

	/*!
	 * @brief Mając numer w indeksie, odszukuje numer w nieposortowanej
	 * tablicy
	 *
	 * Funkcja szuka i zwraca liczbę, która znajduje się pod zadanym
	 * elementem listy. Należy ją interpretować jako sposób przejścia z
	 * indeksu nieposortowanej tablicy do indeksu hipotetycznej,
	 * posortowanej tablicy. */
	unsigned PodIndeksem (unsigned k) const;

	/*!
	 * @brief Szuka właściwego miejsca w Indeksie
	 *
	 * Porównuje klucz z innymi kluczami w tablicy i określa, jakie jest
	 * jego byłoby jego miejsce w posortowanej tablicy. Funkcja jest
	 * zaimplementowana algorytmem podobnym do przeszukiwania binarnego.
	 * @param[in] k - klucz, któremu szukamy miejsce
	 * @return numer, pod którym w indeksie znajdzie się żądany klucz */
	unsigned ZnajdzMiejsce(const Wezel_t &k) const;

	/*!
	 * \brief Szuka numery sąsiadów węzła
	 *
	 * Funkcja działa podobnie do funkcji \ref Sasiedztwo, jednak zamiast
	 * wartości węzłów podaje ich numery w tablicy węzłów.
	 * @param k - węzeł do wyszukania
	 * @return Wektor z numerami sąsiadów, według tablicy węzłów.
	 */
	vector<unsigned> NrySasiadow(const Wezel_t &k) const;

	/*!
	 * \brief Szuka numery sąsiadów węzła
	 *
	 * Funkcja działa podobnie do funkcji \ref Sasiedztwo, jednak zamiast
	 * wartości węzłów podaje ich numery w tablicy węzłów.
	 * @param k - numer węzła w macierzy sąsiedztwa
	 * @return Wektor z numerami sąsiadów, według tablicy węzłów.
	 */
	vector<unsigned> NrySasiadow(unsigned i) const;
<<<<<<< HEAD
=======

	/*!
	 * Zmienna zliczająca operacje, jakie są dokonywane wewnątrz grafu
	 * podczas ich przechodzenia
	 */
	static long licznik;
>>>>>>> origin/master
};

#endif /* GRAF_HH_ */
