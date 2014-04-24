/*!
 * \file graf.hh
 *
 *  Created on: 24 kwi 2014
 *      \author: szymon
 */

#ifndef GRAF_HH_
#define GRAF_HH_

#include <vector>

#include "macierz.hh"

using namespace std;

/*!
 * \brief Modeluje graf nieskierowany
 *
 * Szablon implementuje pojęcie grafu nieskierowanego. Możliwy jest wybór
 * typów danych, jakimi będą węzeł i koszt krawędzi w grafie.
 * Wewnątrz, do opisania struktury grafu wykorzystywana jest tablica węzłów
 * oraz macierz sąsiedztwa.
 *
 * \tparam Wezel_t typ danych, jaki będzie wykorzystywany do opisania węzła.
 * Musi się wypisywać na strumień operatorem <<.
 * \tparam Koszt_t liczbowy typ danych, który będzie opisywał koszt (wagę)
 * krawędzi w grafie.
 */
template <typename Wezel_t, typename Koszt_t>
class Graf {
public:

	/*!
	 * Tablica węzłów istniejących w grafie
	 */
	vector<Wezel_t> Wezly;
private:


};


#endif /* GRAF_HH_ */
