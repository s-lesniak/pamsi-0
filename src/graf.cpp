/*!
 * \file graf.cpp
 *
 *  Created on: 24 kwi 2014
 *      \author: szymon
 */

#include <stdexcept>
#include <queue>
#include <algorithm>

#include "graf.hh"

using namespace std;

template <typename Wezel_t, typename Koszt_t>
bool Graf<Wezel_t, Koszt_t>::Dodaj(const Wezel_t& elem)
{
	try {
		Znajdz(elem);
	}
	catch (const out_of_range &e) {
		list<unsigned>::iterator it = Indeks.begin();
		unsigned poz = ZnajdzMiejsce(elem);
		for (unsigned i = 0; i < poz; i++)
			it++;

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
	for (int j = 0; i < Wezly.size(); j++) {
		if (MSas(j, i))
			wynik.push_back(j);
	}

	return wynik;
}

template <typename Wezel_t, typename Koszt_t>
vector<unsigned> Graf<Wezel_t, Koszt_t>::BFS
(const Wezel_t& start, const Wezel_t& koniec) const
{
	unsigned cel = Znajdz(koniec);

	queue<unsigned> kolejka;
	vector<unsigned> V;
	kolejka.push(Znajdz(start));
	V.push_back(Znajdz(start));

	while (!kolejka.empty()) {
		unsigned i = kolejka.front();
		kolejka.pop();
		if (i == cel)
			return V;
		vector<unsigned> sasiedzi = NrySasiadow(i);
		for (unsigned j = 0; j < sasiedzi.size(); j++) {
			unsigned k = sasiedzi[j];
			if (!count(V.begin(), V.end(), k) ) {
				V.push_back(k);
				kolejka.push(k);
			}
		}
	}
	vector<unsigned> wynik;
	while (!kolejka.empty()) {
		wynik.push_back(kolejka.front());
		kolejka.pop();
	}
	return wynik;
}

template <typename Wezel_t, typename Koszt_t>
vector<unsigned> Graf<Wezel_t, Koszt_t>::DFS
(const Wezel_t& start, const Wezel_t& koniec) const
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

#include <string>

#include "punkt.hh"

template class Graf<string, double>;
template class Graf<Punkt, double>;
