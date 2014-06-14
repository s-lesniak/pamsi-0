/*!
 * \file graf.cpp
 *
 *  Created on: 24 kwi 2014
 *      \author: szymon
 */

#include <stdexcept>
#include <queue>
#include <algorithm>
#include <map>
#include <fstream>
#include <sstream>

#include "graf.hh"

using namespace std;

template <typename Wezel_t, typename Koszt_t>
bool Graf<Wezel_t, Koszt_t>::Dodaj(const Wezel_t& elem)
{
	if (!Wezly.size()) {
		Wezly.push_back(elem);
		MSas.Powieksz(1);
		Indeks.insert(Indeks.begin(), Wezly.size()-1);
		return true;
	}
	try {
		Znajdz(elem);
	}
	catch (const out_of_range &e) {
		list<unsigned>::iterator it = Indeks.begin();
		unsigned poz = ZnajdzMiejsce(elem);
		for (unsigned i = 0; i < poz; i++)
			it++;

//		Indeks.insert(it, Wezly.size()-1);
		Indeks.insert(it, Wezly.size());

		Wezly.push_back(elem);
		MSas.Powieksz(1);

		return true;
	}

	return false;
}

template <typename Wezel_t, typename Koszt_t>
bool Graf<Wezel_t, Koszt_t>::Dodaj(const Wezel_t& elem1, const Wezel_t &elem2,
		const Koszt_t& koszt)
{
	unsigned i, j;
	try {
		i = Znajdz(elem1);
		j = Znajdz(elem2);
	}
	catch (const out_of_range& e) {
		return false;
	}

	MSas(i, j) = MSas(j, i) = koszt;

	return true;
}

template <typename Wezel_t, typename Koszt_t>
bool Graf<Wezel_t, Koszt_t>::Usun(const Wezel_t &elem)
{
	unsigned i;
	try {
		i = Znajdz(elem);
	}
	catch (const out_of_range &e) {
		return false;
	}
	MSas.Usun(i);
	Wezly.erase(Wezly.begin() + i);
	list<unsigned>::iterator to_usun;
	for (list<unsigned>::iterator it = Indeks.begin(); it != Indeks.end();
			it++) {
		if (*it == i)
			to_usun = it;
		if (*it > i)
			(*it)--;
	}
	Indeks.erase(to_usun);
	return true;
}

template <typename Wezel_t, typename Koszt_t>
vector<Wezel_t> Graf<Wezel_t, Koszt_t>::Sasiedztwo(const Wezel_t & elem) const
{
	vector<Wezel_t> wynik;
	unsigned n = Znajdz(elem);
	for (int i = 0; i < Wezly.size(); i++) {
		if (MSas(i, n))
			wynik.push_back(Wezly[i]);
	}

	return wynik;
}

template <typename Wezel_t, typename Koszt_t>
vector<unsigned> Graf<Wezel_t, Koszt_t>::NrySasiadow
(const Wezel_t & elem) const
{
	vector<unsigned> wynik;
	unsigned n = Znajdz(elem);
	for (int i = 0; i < Wezly.size(); i++) {
		if (MSas(i, n))
			wynik.push_back(i);
	}

	return wynik;
}

template <typename Wezel_t, typename Koszt_t>
vector<unsigned> Graf<Wezel_t, Koszt_t>::NrySasiadow
(unsigned i) const
{
	vector<unsigned> wynik;
	for (int j = 0; j < Wezly.size(); j++) {
		if (MSas(j, i))
			wynik.push_back(j);
	}

	return wynik;
}

template <typename Wezel_t, typename Koszt_t>
vector<unsigned> Graf<Wezel_t, Koszt_t>::BFS
(unsigned start, unsigned koniec) const
{
	queue<unsigned> kolejka;
	vector<unsigned> V;  // spis odwiedzonych węzłów
	map<unsigned, unsigned> ojcowie; /* dla każdego odwiedzonego węzła
	 	 	 	 	 	 	 	 	  * zapisuje, skąd do niego przyszliśmy */
	unsigned i;
	kolejka.push(start);
	V.push_back(start);

	while (!kolejka.empty()) {
		i = kolejka.front();
		kolejka.pop();
		if (i == koniec)
			break;
		vector<unsigned> sasiedzi = NrySasiadow(i);
		for (unsigned j = 0; j < sasiedzi.size(); j++) {
			unsigned k = sasiedzi[j];
			if (!count(V.begin(), V.end(), k) ) {
				V.push_back(k);
				kolejka.push(k);
				ojcowie[k] = i;
			}
		}
	}
	vector<unsigned> wynik;
	do {
		wynik.push_back(i);
		i = ojcowie[i];
	} while (i != start);
	wynik.push_back(start);

	return wynik;
}

template <typename Wezel_t, typename Koszt_t>
vector<unsigned> Graf<Wezel_t, Koszt_t>::DFS
(unsigned start, unsigned koniec) const
{

}

template <typename Wezel_t, typename Koszt_t>
vector<unsigned> Graf<Wezel_t, Koszt_t>::AStar
(unsigned start, unsigned koniec) const
{

}

template <typename Wezel_t, typename Koszt_t>
vector<Wezel_t> Graf<Wezel_t, Koszt_t>::ZnajdzWartosci
(const vector<unsigned>& zr) const
{
	vector<Wezel_t> wynik;
	for (int i = 0; i < zr.size(); i++)
		wynik.push_back(Wezly[i]);

	return wynik;
}

template <typename Wezel_t, typename Koszt_t>
unsigned Graf<Wezel_t, Koszt_t>::Znajdz(const Wezel_t & elem) const
{
	unsigned l = 0, p = Wezly.size() - 1, sr;

	while (l+1 <= p+1) { // zapobiega problemom przepełnionego licznika
		sr = (l+p) / 2;

		if (Wezly[PodIndeksem(sr)] == elem)
			return PodIndeksem(sr);
		if (Wezly[PodIndeksem(sr)] < elem)
			l = sr + 1;
		else
			p = sr - 1;
	}

	throw out_of_range("Znajdz()");
}

template <typename Wezel_t, typename Koszt_t>
unsigned Graf<Wezel_t, Koszt_t>::PodIndeksem (unsigned k) const
{
  list<unsigned>::const_iterator it = Indeks.begin();
  for (unsigned i = 0; i < k; i++)
    it++;

  return *it;
}

template <typename Wezel_t, typename Koszt_t>
unsigned Graf<Wezel_t, Koszt_t>::ZnajdzMiejsce(const Wezel_t &k) const
{
	int l = 0, p = Wezly.size(), sr;

	while (l <= p) {
		sr = (l+p) / 2;

		if (Wezly[PodIndeksem(sr)] <= k) {
			if (sr+1 == Wezly.size())
				return sr+1;
			else {
				if (k <= Wezly[PodIndeksem(sr+1)])
					return sr+1;
				else
					l = sr+1;
			}
		}
		else
			p = sr-1;
	}
	return 0;
}

template <typename Wezel_t, typename Koszt_t>
Koszt_t Graf<Wezel_t, Koszt_t>::LacznyKoszt(const vector<unsigned>& sciezka)
{
	Koszt_t wynik = 0.0;

	for (unsigned i = 1; i < sciezka.size(); i++) {
		Koszt_t skladowa = Odleglosc(sciezka[i-1], sciezka[i]);
		if (!skladowa)
			return -1.0;
		wynik += skladowa;
	}

	return wynik;
}

template <typename Wezel_t, typename Koszt_t>
void Graf<Wezel_t, Koszt_t>::WczytajWierzcholki()
{
	ifstream str;
	string nazwa_pliku;
	while (!str.is_open()) {
		cout << "Podaj nazwę pliku z wierzchołkami: ";
		cin >> nazwa_pliku;
		str.open(nazwa_pliku.c_str());
	}

	while (str.good()) {
		Punkt nowy;
		str >> nowy;
		Dodaj(nowy);
	}
	Punkt pusty;
	Usun(pusty);
}

template <typename Wezel_t, typename Koszt_t>
void Graf<Wezel_t, Koszt_t>::WczytajKrawedzie()
{
	ifstream str;
	string nazwa_pliku;
	while (!str.is_open()) {
		cout << "Podaj nazwę pliku z krawędziami: ";
		cin >> nazwa_pliku;
		str.open(nazwa_pliku.c_str());
	}

	string linijka, start, koniec;
	while (str.good()) {
		getline(str, linijka);
		istringstream sstr(linijka);
		getline(sstr, start, ',');
		getline(sstr, koniec, ',');

		Koszt_t waga;
		sstr >> waga;

		Dodaj(start, koniec, waga);
	}
}

template <typename Wezel_t, typename Koszt_t>
void Graf<Wezel_t, Koszt_t>::PokazTrase
(const vector<unsigned> &sciezka, ostream &str)
{
	cout << endl << Wezly[sciezka.back()].Nazwa;
	for (unsigned i = sciezka.size()-2; i < sciezka.size(); i--)
		cout << " --(" << Odleglosc(sciezka[i+1], sciezka[i]) << " km)--> "
		<< Wezly[sciezka[i]].Nazwa;

	cout << endl;
}

#include <string>

#include "punkt.hh"

template class Graf<Punkt, double>;
//template class Graf<string, double>;
